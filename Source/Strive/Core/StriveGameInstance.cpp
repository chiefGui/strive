// Fill out your copyright notice in the Description page of Project Settings.

#include "StriveGameInstance.h"
#include "MoviePlayer.h"

void UStriveGameInstance::Init() 
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UStriveGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UStriveGameInstance::EndLoadingScreen);

	if (DefaultLoadingScreenWidget)
	{
		LoadingScreenWidget = CreateWidget<UUserWidget>(this, DefaultLoadingScreenWidget);
	}
}

void UStriveGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (!IsRunningDedicatedServer() && DefaultLoadingScreenWidget)
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.MinimumLoadingScreenDisplayTime = -1;
		LoadingScreen.WidgetLoadingScreen = LoadingScreenWidget->TakeWidget();

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}
}

void UStriveGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{

}