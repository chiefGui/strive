#include "GameSparksPrivatePCH.h"

// since UE 4.15 the cleanup we're doing our selfes no longer works
#if defined(_MSC_VER) && !defined(_DURANGO) && GS_UE_VERSION >= GS_MAKE_VERSION(4, 15)
#	define GS_USE_UE_WINDOWS_PLATFORM_TYPES
#endif

#if defined(GS_USE_UE_WINDOWS_PLATFORM_TYPES)
#	include "AllowWindowsPlatformTypes.h"
#endif

#if !defined(GS_BUILDING_DLL)
#	define GS_BUILDING_DLL 1
#endif /* !defined(GS_BUILDING_DLL) */

#if defined(_MSC_VER)
#	pragma warning(disable: 4251)
#endif

#include "../../GameSparksBaseSDK/src/GameSparksAll.cpp"

#if defined(GS_USE_UE_WINDOWS_PLATFORM_TYPES)
#	include "HideWindowsPlatformTypes.h"
#endif

// additional cleanup for UE <= 4.14
#if defined(_MSC_VER) && defined(CDECL) && GS_UE_VERSION <= GS_MAKE_VERSION(4, 14)
#	undef CDECL
#endif
