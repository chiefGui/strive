
#pragma once


#define GS_USE_STD_FUNCTION 1

#if !defined(GS_COMPILER_HAS_NULLPTR_SUPPORT)
#	define GS_COMPILER_HAS_NULLPTR_SUPPORT 1
#endif

#define __NUMBERFORMATTING__ //avoid clashed with CarbonCore.framework/Headers/NumberFormatting.h

//#include "Engine.h"
//#include "GameSparksClasses.h"

// in source builds "Engine.h" is included instead of "PrivatePCH.h" in the auto generated Module.cpp
// we use this to detect if we're currently building against a source build or against a precompiled
// version of unreal.
#if defined(_MSC_VER)
#	if defined(MAX_AUDIOCHANNELS) // arbitrary, defined in Audio.h
#		define GS_UE_IS_SOURCE_BUILD 1
#	endif
#endif

#include "Runtime/Launch/Resources/Version.h"

#if !defined(GS_MAKE_VERSION)
#   define GS_MAKE_VERSION(major, minor) (major*100 + minor)
#   define GS_UE_VERSION GS_MAKE_VERSION(ENGINE_MAJOR_VERSION, ENGINE_MINOR_VERSION)
#endif

//DECLARE_LOG_CATEGORY_EXTERN(Victory, Log, All);
