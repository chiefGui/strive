// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Core.h"
#include "ModuleManager.h"

#include "Json.h"

#include "OnlineSubsystemGameSparks.h"
#include "OnlineSubsystemGameSparksModule.h"

/** pre-pended to all GameSparks logging */
#undef ONLINE_LOG_PREFIX
#define ONLINE_LOG_PREFIX TEXT("GameSparks: ")

DECLARE_LOG_CATEGORY_EXTERN(GSOSSLog, Log, All);

#include "Runtime/Launch/Resources/Version.h"

#if !defined(GS_MAKE_VERSION)
#   define GS_MAKE_VERSION(major, minor) (major*100 + minor)
#   define GS_UE_VERSION GS_MAKE_VERSION(ENGINE_MAJOR_VERSION, ENGINE_MINOR_VERSION)
#endif

#include <GameSparks/generated/GSRequests.h>
#include <GameSparks/generated/GSResponses.h>
#include <GameSparks/generated/GSMessages.h>
#include <GameSparks/GS.h>
