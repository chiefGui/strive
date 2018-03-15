#include "UGSRTVector.h"
#include "../GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

UGSRTVector::UGSRTVector(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}

void UGSRTVector::SetRTVector(const GameSparks::RT::RTVector& vector)
{
    m_Data = vector;
};

const GameSparks::RT::RTVector& UGSRTVector::GetRTVector() const
{
	return m_Data;
}

UGSRTVector* UGSRTVector::CreateRTVector(UObject* WorldContextObject){
    UGSRTVector* proxy = NewObject<UGSRTVector>();
    return proxy;
};

bool UGSRTVector::HasX()
{
	return m_Data.x.HasValue();
}

bool UGSRTVector::HasY()
{
	return m_Data.y.HasValue();
}

bool UGSRTVector::HasZ()
{
	return m_Data.z.HasValue();
}

bool UGSRTVector::HasW()
{
	return m_Data.w.HasValue();
}


float UGSRTVector::GetX()
{
	return m_Data.x.GetValueOrDefault(0.0f);
}

float UGSRTVector::GetY()
{
	return m_Data.y.GetValueOrDefault(0.0f);
}

float UGSRTVector::GetZ()
{
	return m_Data.z.GetValueOrDefault(0.0f);
}

float UGSRTVector::GetW()
{
	return m_Data.w.GetValueOrDefault(0.0f);
}


UGSRTVector* UGSRTVector::SetX(float x)
{
	m_Data.x = x;
	return this;
}

UGSRTVector* UGSRTVector::SetY(float y)
{
	m_Data.y = y;
	return this;
}

UGSRTVector* UGSRTVector::SetZ(float z)
{
	m_Data.z = z;
	return this;
}

UGSRTVector* UGSRTVector::SetW(float w)
{
	m_Data.w = w;
	return this;
}

UGSRTVector* UGSRTVector::SetXY(float x, float y)
{
	m_Data.x = x;
	m_Data.y = y;
	return this;
}

UGSRTVector* UGSRTVector::SetXYZ(float x, float y, float z)
{
	m_Data.x = x;
	m_Data.y = y;
	m_Data.z = z;
	return this;
}

UGSRTVector* UGSRTVector::SetXYZW(float x, float y, float z, float w)
{
	m_Data.x = x;
	m_Data.y = y;
	m_Data.z = z;
	m_Data.w = w;
	return this;
}


UGSRTVector* UGSRTVector::SetFromFVector(const FVector& v)
{
	m_Data.x = v.X;
	m_Data.y = v.Y;
	m_Data.z = v.Z;
	return this;
}

FVector UGSRTVector::GetFVector() const
{
	return FVector(
		m_Data.x.GetValueOrDefault(0.0f),
		m_Data.y.GetValueOrDefault(0.0f),
		m_Data.z.GetValueOrDefault(0.0f)
	);
}
