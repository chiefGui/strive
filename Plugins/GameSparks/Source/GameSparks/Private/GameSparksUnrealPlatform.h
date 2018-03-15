#pragma once

#include <GameSparks/IGSPlatform.h>
#include <GameSparks/GSPlatformDeduction.h>
#include "GameSparksModule.h"

#include "Runtime/Launch/Resources/Version.h"

#if !defined(GS_MAKE_VERSION)
#   define GS_MAKE_VERSION(major, minor) (major*100 + minor)
#   define GS_UE_VERSION GS_MAKE_VERSION(ENGINE_MAJOR_VERSION, ENGINE_MINOR_VERSION)
#endif

namespace GameSparks
{
	namespace UnrealEngineSDK
	{
		class GameSparksUnrealPlatform : public GameSparks::Core::IGSPlatform
		{
		public:
			GameSparksUnrealPlatform(const gsstl::string& apikey, const gsstl::string& secret, bool previewServer)
				: GameSparks::Core::IGSPlatform(apikey, secret, previewServer)
			{
			}

			gsstl::string GetDeviceId() const override
			{
				#if GS_UE_VERSION > GS_MAKE_VERSION(4, 14)
				return TCHAR_TO_UTF8(*FPlatformMisc::GetDeviceId());
				#else
				return TCHAR_TO_UTF8(*FPlatformMisc::GetUniqueDeviceId());
				#endif
			}

			gsstl::string GetDeviceOS() const override
			{
				return FPlatformProperties::IniPlatformName();
			}

			gsstl::string GetPlatform() const override
			{
				return FPlatformProperties::PlatformName();
			}

			gsstl::string GetSDK() const override
			{
				return "GameSparks Unreal Engine SDK";
			}

			gsstl::string GetEngine() const override
			{
				return "Unreal Engine";
			}

			gsstl::string GetEngineVersion() const override
			{
				std::stringstream ss;
				ss << ENGINE_MAJOR_VERSION << "." << ENGINE_MINOR_VERSION << "." << ENGINE_PATCH_VERSION;
				return ss.str();
			}

			gsstl::string GetDeviceType() const override
			{
				#if PLATFORM_DESKTOP
					return "Desktop";
				#else
					return "Handheld";
				#endif	
			}

			bool GetExtraDebug() const override
			{
				return true;
			}

			void DebugMsg(const gsstl::string& message) const override
			{
				if (UGameSparksModule::GetModulePtr())
					UGameSparksModule::GetModulePtr()->SendDebugLogToComponents(message);
			}

            virtual gsstl::string ToWritableLocation(gsstl::string desired_name) const{
                #if PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_PS4 || defined(__ORBIS__)
					// Conditional since ConvertRelativePathToFull does not work on mobile devices.
					// see https://answers.unrealengine.com/questions/120796/adding-custom-files-to-the-android-content.html
					return GameSparks::Core::IGSPlatform::ToWritableLocation(desired_name);
                #else
                    #if GS_UE_VERSION >= GS_MAKE_VERSION(4, 18) // GameSavedDir has been deprecated in 4.18
                        FString writeableLocation = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());
                    #else
                        FString writeableLocation = FPaths::ConvertRelativePathToFull(FPaths::GameSavedDir());
                    #endif
                    writeableLocation += "gamesparks_";
                    writeableLocation += FString(UTF8_TO_TCHAR(desired_name.c_str()));
                    return TCHAR_TO_UTF8(*writeableLocation);
				#endif
            }
		};
	}
}
