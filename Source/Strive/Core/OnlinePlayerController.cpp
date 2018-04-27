// Fill out your copyright notice in the Description page of Project Settings.

#include "OnlinePlayerController.h"

FString AOnlinePlayerController::GetSessionTicket()
{
	FString SessionTicket = OnlineInterface->GetIdentityInterface()->GetAuthToken(0);

	return SessionTicket;
}
