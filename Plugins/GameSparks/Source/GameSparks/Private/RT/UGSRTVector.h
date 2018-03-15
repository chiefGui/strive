#pragma once
#include "../GameSparksPrivatePCH.h"
#include "Engine.h"

#if !defined(GS_BUILDING_DLL)
#       define GS_BUILDING_DLL 1
#endif /* !defined(GS_BUILDING_DLL) */

#include <GameSparksRT/RTData.hpp>
#include <memory>
#include "UGSRTVector.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UGSRTVector : public UObject
{
		GENERATED_UCLASS_BODY()
	public:
		void SetRTVector(const GameSparks::RT::RTVector& vector);
		const GameSparks::RT::RTVector& GetRTVector() const;
		FVector GetFVector() const;

		/* Create a new GS Vector object. */
		UFUNCTION(BlueprintPure, meta = (DisplayName = "Create GS RT Vector", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "GameSparksRT|Vector")
		static UGSRTVector* CreateRTVector(UObject* WorldContextObject);

		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		bool HasX();
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		bool HasY();
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		bool HasZ();
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		bool HasW();

		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		float GetX();
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		float GetY();
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		float GetZ();
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		float GetW();


		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		UGSRTVector* SetX(float x);
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		UGSRTVector* SetY(float y);
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		UGSRTVector* SetZ(float z);
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		UGSRTVector* SetW(float w);

		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		UGSRTVector* SetXY(float x, float y);
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		UGSRTVector* SetXYZ(float x, float y, float z);
		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		UGSRTVector* SetXYZW(float x, float y, float z, float w);

		UFUNCTION(BlueprintPure, Category = "GameSparksRT|Vector")
		UGSRTVector* SetFromFVector(const FVector& v);
	protected:
		GameSparks::RT::RTVector m_Data;
};
