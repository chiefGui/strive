#include "UGSRTData.h"
#include "../GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"
#include <sstream>

DECLARE_LOG_CATEGORY_EXTERN(UGameSparksRTDataLog, Log, All);
DEFINE_LOG_CATEGORY(UGameSparksRTDataLog);

UGSRTData::UGSRTData(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

void UGSRTData::SetRTData(const GameSparks::RT::RTData& data)
{
    m_Data = data;
};

const GameSparks::RT::RTData& UGSRTData::GetRTData() const
{
    return m_Data;
}

UGSRTData* UGSRTData::CreateRTData(UObject* WorldContextObject){
    UGSRTData* proxy = NewObject<UGSRTData>();
    return proxy;
};

static bool indexIsValid(int32 index)
{
	if (index < 1)
	{
		UE_LOG(UGameSparksRTDataLog, Error, TEXT("%s"), TEXT("RTData index must be greater than zero."));
		return false;
	}
	if (index >= GameSparks::RT::GameSparksRT::MAX_RTDATA_SLOTS)
	{
		UE_LOG(UGameSparksRTDataLog, Error, TEXT("RTData index must be less than %s."), int32(GameSparks::RT::GameSparksRT::MAX_RTDATA_SLOTS));
		return false;
	}
	return true;
}


bool UGSRTData::HasInt(int32 index)
{
	if (!indexIsValid(index)) return{};
	return m_Data.GetInt(index).HasValue();
}

bool UGSRTData::HasVector(int32 index)
{
	if (!indexIsValid(index)) return{};
    return m_Data.GetRTVector(index).HasValue();
}

bool UGSRTData::HasFloat(int32 index)
{
	if (!indexIsValid(index)) return{};
    return m_Data.GetFloat(index).HasValue();
}

bool UGSRTData::HasString(int32 index)
{
	if (!indexIsValid(index)) return{};
    return m_Data.GetString(index).HasValue();
}

bool UGSRTData::HasData(int32 index)
{
	if (!indexIsValid(index)) return{};
    return m_Data.GetData(index).HasValue();
}


int32 UGSRTData::GetInt(int32 index)
{
	if (!indexIsValid(index)) return{};
    return m_Data.GetInt(index).GetValueOrDefault(0);
}

UGSRTVector* UGSRTData::GetVector(int32 index)
{
	if (!indexIsValid(index)) return NewObject<UGSRTVector>();
	UGSRTVector* ret = NewObject<UGSRTVector>();
	ret->SetRTVector(m_Data.GetRTVector(index).GetValueOrDefault(GameSparks::RT::RTVector()));
	return ret;
}

FVector UGSRTData::GetFVector(int32 index)
{
	if (!indexIsValid(index)) return{};
	auto v = m_Data.GetRTVector(index).GetValueOrDefault(GameSparks::RT::RTVector());
	return FVector(
		v.x.GetValueOrDefault(0.0f),
		v.y.GetValueOrDefault(0.0f),
		v.z.GetValueOrDefault(0.0f)
	);
}


float UGSRTData::GetFloat(int32 index)
{
	if (!indexIsValid(index)) return{};
    return m_Data.GetFloat(index).GetValueOrDefault(0.0f);
}

FString UGSRTData::GetString(int32 index)
{
	if (!indexIsValid(index)) return{};
    return FString(UTF8_TO_TCHAR(m_Data.GetString(index).GetValueOrDefault("").c_str()));
}

UGSRTData* UGSRTData::GetData(int32 index)
{
	if (!indexIsValid(index)) return NewObject<UGSRTData>();
	UGSRTData* ret = NewObject<UGSRTData>();
	ret->SetRTData(m_Data.GetData(index).GetValueOrDefault(GameSparks::RT::RTData()));
	return ret;
}


UGSRTData* UGSRTData::SetInt(int32 index, int32 value)
{
	if (!indexIsValid(index)) return this;
    m_Data.SetInt(index, value);
    return this;
}

UGSRTData* UGSRTData::SetVector(int32 index, UGSRTVector* value)
{
	if (!indexIsValid(index)) return this;
    m_Data.SetRTVector(index, value->GetRTVector());
    return this;
}

UGSRTData* UGSRTData::SetFVector(int32 index, const FVector& value)
{
	if (!indexIsValid(index)) return this;
	m_Data.SetRTVector(index, {value.X, value.Y, value.Z});
	return this;
}


UGSRTData* UGSRTData::SetFloat(int32 index, float value)
{
	if (!indexIsValid(index)) return this;
    m_Data.SetFloat(index, value);
    return this;
}

UGSRTData* UGSRTData::SetString(int32 index, const FString& value)
{
	if (!indexIsValid(index)) return this;
    m_Data.SetString(index, TCHAR_TO_UTF8(*value));
    return this;
}

UGSRTData* UGSRTData::SetData(int32 index, UGSRTData* value)
{
	if (!indexIsValid(index)) return this;
	m_Data.SetData(index, value->GetRTData());
	return this;
}

FString UGSRTData::ToString()
{
	std::stringstream ss;
	ss << m_Data;
	return FString(UTF8_TO_TCHAR(ss.str().c_str()));
}
