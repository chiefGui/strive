#include "UGSRTSession.h"
#include "../GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

DECLARE_LOG_CATEGORY_EXTERN(UGameSparksRTSessionLog, Log, All);
DEFINE_LOG_CATEGORY(UGameSparksRTSessionLog);

UGSRTSession::UGSRTSession(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
UGSRTSession::~UGSRTSession()
{
	Stop();
}

UGSRTSession* UGSRTSession::CreateRTSession(UObject* WorldContextObject, FString host, FString port, FString token)
{
	UGSRTSession* proxy = NewObject<UGSRTSession>();

	proxy->sessionListener.Reset(new RTSessionListenerProxy(proxy));

	proxy->session.Reset(GameSparks::RT::GameSparksRTSessionBuilder()
		.SetListener(proxy->sessionListener.Get())
		.SetHost(TCHAR_TO_UTF8(*host))
		.SetPort(TCHAR_TO_UTF8(*port))
		.SetConnectToken((TCHAR_TO_UTF8(*token)))
		.Build());

	return proxy;
}

void UGSRTSession::Start()
{
	std::lock_guard<std::recursive_mutex > lock(sessionMutex);
	if (session)
	{
		session->Start();
		started = true;
	}
}


void UGSRTSession::Stop()
{
	std::lock_guard<std::recursive_mutex > lock(sessionMutex);
	if (session)
	{
		started = false;
		session->Stop();
	}
}

/*bool UGSRTSession::IsReady()
{
	if (!session)
		return false;
	return session->Ready;
}*/

void UGSRTSession::Send(int32 opCode, DeliveryIntent intent, UGSRTData* data, TArray<int32> peerIds_)
{
	if (!data)
	{
		UE_LOG(UGameSparksRTSessionLog, Error, TEXT("%s"), TEXT("Send() requires a data abject"));
		return;
	}

	std::vector<int> peerIds(peerIds_.Num());
	std::copy(peerIds_.GetData(), peerIds_.GetData() + peerIds_.Num(), peerIds.begin());

	if (!session || !IsReady)
	{
		UE_LOG(UGameSparksRTSessionLog, Error, TEXT("%s"), TEXT("RT Session must be started and ready before you send."));
		return;
	}

	if (opCode <= 0)
	{
		UE_LOG(UGameSparksRTSessionLog, Error, TEXT("%s"), TEXT("OpCode must be greater than zero!"));
		return;
	}

	std::lock_guard<std::recursive_mutex> lock(sessionMutex);
	session->SendRTData(opCode, (GameSparks::RT::GameSparksRT::DeliveryIntent)intent, data->GetRTData(), peerIds);
}


TArray<int32> UGSRTSession::GetActivePeers()
{
	std::lock_guard<std::recursive_mutex> lock(sessionMutex);
	if (!session) return{};

	TArray<int32> ret;
	ret.SetNum(session->ActivePeers.size());
	std::copy(session->ActivePeers.begin(), session->ActivePeers.end(), ret.GetData());

	return ret;
}


int32 UGSRTSession::GetPeerId()
{
	std::lock_guard<std::recursive_mutex> lock(sessionMutex);
	if (!session) return -1;
	return session->PeerId.GetValueOrDefault(-1);
}


void UGSRTSession::OnPlayerConnect(int peerId)
{
	OnPlayerConnectDelegate.Broadcast(this, peerId);
	/*if (OnPlayerConnectDelegate.IsBound())
	{

	}*/
}

void UGSRTSession::OnPlayerDisconnect(int peerId)
{
	OnPlayerDisconnectDelegate.Broadcast(this, peerId);
}

void UGSRTSession::OnReady(bool ready)
{
	IsReady = ready;
	OnReadyDelegate.Broadcast(this, ready);
}

void UGSRTSession::OnPacket(const GameSparks::RT::RTPacket& packet)
{
	UGSRTData* data = NewObject<UGSRTData>();
	data->SetRTData(packet.Data);
	OnDataDelegate.Broadcast(this, packet.Sender, packet.OpCode, data);
}


void UGSRTSession::Tick(float DeltaTime)
{
	std::lock_guard<std::recursive_mutex> lock(sessionMutex);
	if (session && started)
	{
		session->Update();
	}
}

bool UGSRTSession::IsTickable() const
{
	return true;
}

TStatId UGSRTSession::GetStatId() const
{
	return UObject::GetStatID();
}
