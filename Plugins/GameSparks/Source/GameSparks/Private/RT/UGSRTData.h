#pragma once
#include "../GameSparksPrivatePCH.h"
#include "Engine.h"

#if !defined(GS_BUILDING_DLL)
#       define GS_BUILDING_DLL 1
#endif /* !defined(GS_BUILDING_DLL) */

#include <GameSparksRT/RTData.hpp>
#include <memory>
#include "UGSRTVector.h"
#include "UGSRTData.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UGSRTData : public UObject
{
                GENERATED_UCLASS_BODY()
        public:
                void SetRTData(const GameSparks::RT::RTData& data);
                const GameSparks::RT::RTData& GetRTData() const;

                /* Create a new GS Data object. */
                UFUNCTION(BlueprintPure, meta = (DisplayName = "Create GS RT Data", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameSparksRT|Data")
                static UGSRTData* CreateRTData(UObject* WorldContextObject);

                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                bool HasInt(int32 index);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                bool HasVector(int32 index);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                bool HasFloat(int32 index);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                bool HasString(int32 index);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                bool HasData(int32 index);

                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
				int32 GetInt(int32 index);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                UGSRTVector* GetVector(int32 index);
				UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
				FVector GetFVector(int32 index);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                float GetFloat(int32 index);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                FString GetString(int32 index);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                UGSRTData* GetData(int32 index);

                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                UGSRTData* SetInt(int32 index, int32 value);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                UGSRTData* SetVector(int32 index, UGSRTVector* value);
				UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
				UGSRTData* SetFVector(int32 index, const FVector& value);
				UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                UGSRTData* SetFloat(int32 index, float value);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                UGSRTData* SetString(int32 index, const FString& value);
                UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
                UGSRTData* SetData(int32 index, UGSRTData* value);

				UFUNCTION(BlueprintPure, Category = "GameSparksRT|Data")
				FString ToString();
        protected:
                GameSparks::RT::RTData m_Data;
};
