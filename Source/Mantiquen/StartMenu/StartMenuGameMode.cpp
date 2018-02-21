// Fill out your copyright notice in the Description page of Project Settings.

#include "StartMenuGameMode.h"

void AStartMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	GLog->Log("Hello from C++!");
}