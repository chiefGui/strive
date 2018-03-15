#include "GameSparksScriptData.h"
#include "GameSparksPrivatePCH.h"
#include "Engine.h"
#include "GameSparksClasses.h"

void UGameSparksScriptData::SetGSData(const GameSparks::Core::GSData& data)
{
    m_Data = data;
};

UGameSparksScriptData* UGameSparksScriptData::CreateGameSparksScriptData(UObject* WorldContextObject){
    UGameSparksScriptData* proxy = NewObject<UGameSparksScriptData>();
    proxy->m_Data = GameSparks::Core::GSRequestData();
    return proxy;
};

FString UGameSparksScriptData::JSONString() const
{
    return FString(UTF8_TO_TCHAR(m_Data.GetJSON().c_str()));
}

FString UGameSparksScriptData::ToString() const
{
	return JSONString();
}

bool UGameSparksScriptData::HasString(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetString(TCHAR_TO_UTF8(*name)).HasValue();
};

FString UGameSparksScriptData::GetString(const FString& name) const
{
    if(m_Data.GetString(TCHAR_TO_UTF8(*name)).HasValue())
    {
        std::string str = m_Data.GetString(TCHAR_TO_UTF8(*name)).GetValue();
        return FString(UTF8_TO_TCHAR(str.c_str()));
    }
    {
        return FString();
    }
}

UGameSparksScriptData* UGameSparksScriptData::SetString(const FString& name, const FString& value){
    m_Data.AddString(TCHAR_TO_UTF8(*name), TCHAR_TO_UTF8(*value));
    return this;
};

bool UGameSparksScriptData::HasStringArray(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetStringList(TCHAR_TO_UTF8(*name)).size() > 0;
};

TArray<FString> UGameSparksScriptData::GetStringArray(const FString& name) const
{
    TArray<FString> newArray;
    gsstl::vector<gsstl::string> data = m_Data.GetStringList(TCHAR_TO_UTF8(*name));
    for(gsstl::vector<gsstl::string>::iterator it = data.begin(); it != data.end(); ++it) {
        newArray.Add(FString(UTF8_TO_TCHAR(it->c_str())));
    }
    return newArray;
};

UGameSparksScriptData* UGameSparksScriptData::SetStringArray(const FString& name, const TArray<FString> value)
{
    gsstl::vector<gsstl::string> arrValue;
    for(int32 b_arrValue = 0; b_arrValue < value.Num(); b_arrValue++)
    {
        arrValue.push_back(TCHAR_TO_UTF8(*value[b_arrValue]));
    }
    m_Data.AddStringList(TCHAR_TO_UTF8(*name), arrValue);
    return this;
};

bool UGameSparksScriptData::HasNumber(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetLong(TCHAR_TO_UTF8(*name)).HasValue();
};

int32 UGameSparksScriptData::GetNumber(const FString& name) const
{
    return m_Data.GetLong(TCHAR_TO_UTF8(*name)).HasValue() ? m_Data.GetLong(TCHAR_TO_UTF8(*name)).GetValue() : 0;
};

UGameSparksScriptData* UGameSparksScriptData::SetNumber(const FString& name, const int32 value)
{
    m_Data.AddNumber(TCHAR_TO_UTF8(*name), value);
    return this;
};

bool UGameSparksScriptData::HasNumberArray(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetLongList(TCHAR_TO_UTF8(*name)).size() > 0;
};

TArray<int32> UGameSparksScriptData::GetNumberArray(const FString& name) const
{
    TArray<int32> newArray;
    gsstl::vector<long> data = m_Data.GetLongList(TCHAR_TO_UTF8(*name));
    for(gsstl::vector<long>::iterator it = data.begin(); it != data.end(); ++it) {
        newArray.Add(*it);
    }
    return newArray;
};

UGameSparksScriptData* UGameSparksScriptData::SetNumberArray(const FString& name, const TArray<int32> value)
{
    gsstl::vector<long> arrValue;
    for(int32 b_arrValue = 0; b_arrValue < value.Num(); b_arrValue++)
    {
        arrValue.push_back(value[b_arrValue]);
    }
    m_Data.AddNumberList(TCHAR_TO_UTF8(*name), arrValue);
    return this;
};

bool UGameSparksScriptData::HasFloat(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetFloat(TCHAR_TO_UTF8(*name)).HasValue();
}

float UGameSparksScriptData::GetFloat(const FString& name) const
{
    return m_Data.GetFloat(TCHAR_TO_UTF8(*name)).HasValue() ? m_Data.GetFloat(TCHAR_TO_UTF8(*name)).GetValue() : 0;
}

UGameSparksScriptData* UGameSparksScriptData::SetFloat(const FString& name, const float value)
{
    m_Data.AddNumber(TCHAR_TO_UTF8(*name), value);
    return this;
}

bool UGameSparksScriptData::HasFloatArray(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetFloatList(TCHAR_TO_UTF8(*name)).size() > 0;
};

TArray<float> UGameSparksScriptData::GetFloatArray(const FString& name) const
{
    TArray<float> newArray;
    gsstl::vector<float> data = m_Data.GetFloatList(TCHAR_TO_UTF8(*name));
    for(gsstl::vector<float>::iterator it = data.begin(); it != data.end(); ++it) {
        newArray.Add(*it);
    }
    return newArray;
};

UGameSparksScriptData* UGameSparksScriptData::SetFloatArray(const FString& name, const TArray<float> value)
{
    gsstl::vector<float> arrValue;
    for(float b_arrValue = 0; b_arrValue < value.Num(); b_arrValue++)
    {
        arrValue.push_back(value[b_arrValue]);
    }
    m_Data.AddNumberList(TCHAR_TO_UTF8(*name), arrValue);
    return this;
};

bool UGameSparksScriptData::HasBoolean(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetBoolean(TCHAR_TO_UTF8(*name)).HasValue();
};

bool UGameSparksScriptData::GetBoolean(const FString& name) const
{
    return m_Data.GetBoolean(TCHAR_TO_UTF8(*name)).HasValue() ? m_Data.GetBoolean(TCHAR_TO_UTF8(*name)).GetValue() : false;
};

UGameSparksScriptData* UGameSparksScriptData::SetBoolean(const FString& name, const bool value)
{
    m_Data.AddBoolean(TCHAR_TO_UTF8(*name), value);
    return this;
};

bool UGameSparksScriptData::HasGSData(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetGSDataObject(TCHAR_TO_UTF8(*name)).HasValue();
};

UGameSparksScriptData* UGameSparksScriptData::GetGSData(const FString& name) const
{
    UGameSparksScriptData* ret = NewObject<UGameSparksScriptData>();
    if(m_Data.GetGSDataObject(TCHAR_TO_UTF8(*name)).HasValue()){
        ret->SetGSData(m_Data.GetGSDataObject(TCHAR_TO_UTF8(*name)).GetValue());
    }
    return ret;
};

UGameSparksScriptData* UGameSparksScriptData::SetGSData(const FString& name,  UGameSparksScriptData* value)
{
    m_Data.AddObject(TCHAR_TO_UTF8(*name), value->ToRequestData());
    return this;
};

bool UGameSparksScriptData::HasGSDataArray(const FString& name) const
{
    return m_Data.ContainsKey(TCHAR_TO_UTF8(*name)) && m_Data.GetGSDataObjectList(TCHAR_TO_UTF8(*name)).size() > 0;
};

TArray<UGameSparksScriptData*> UGameSparksScriptData::GetGSDataArray(const FString& name) const
{
    TArray<UGameSparksScriptData*> newArray;
    gsstl::vector<GameSparks::Core::GSData> data = m_Data.GetGSDataObjectList(TCHAR_TO_UTF8(*name));
    for(gsstl::vector<GameSparks::Core::GSData>::iterator it = data.begin(); it != data.end(); ++it)
    {
        UGameSparksScriptData* ret = NewObject<UGameSparksScriptData>();
        ret->SetGSData(*it);
        newArray.Add(ret);
    }
    return newArray;
};

UGameSparksScriptData* UGameSparksScriptData::SetGSDataArray(const FString& name,  TArray<UGameSparksScriptData*> value)
{
    gsstl::vector<GameSparks::Core::GSData> arrValue;
    for(int32 b_arrValue = 0; b_arrValue < value.Num(); b_arrValue++)
    {
        arrValue.push_back(value[b_arrValue]->ToRequestData());
    }
    m_Data.AddNumberList(TCHAR_TO_UTF8(*name), arrValue);
    return this;
};

bool UGameSparksScriptData::HasDateTime( const FString& name ) const
{
    return m_Data.ContainsKey( TCHAR_TO_UTF8( *name ) ) && m_Data.GetDate( TCHAR_TO_UTF8( *name ) ).HasValue();
}

FDateTime UGameSparksScriptData::GetDateTime( const FString& name ) const
{
    if ( m_Data.GetDate( TCHAR_TO_UTF8( *name ) ).HasValue() )
    {
        GameSparks::Core::GSDateTime date_time = m_Data.GetDate( TCHAR_TO_UTF8( *name ) ).GetValue();
        
        return FDateTime( date_time.GetYear(), date_time.GetMonth(), date_time.GetDay(), date_time.GetHour(), date_time.GetMinute(), date_time.GetSecond() );
    }
    
    return FDateTime();
}

UGameSparksScriptData* UGameSparksScriptData::SetDateTime( const FString& name, const FDateTime & value )
{
    GameSparks::Core::GSDateTime date_time( value.GetDay(), value.GetMonth(), value.GetYear(), value.GetHour(), value.GetMinute(), value.GetSecond(), false );
    m_Data.AddDate( TCHAR_TO_UTF8( *name ), date_time );
    return this;
}

bool UGameSparksScriptData::HasIntArray( const FString& name ) const
{
    return m_Data.ContainsKey( TCHAR_TO_UTF8( *name ) ) && m_Data.GetIntList( TCHAR_TO_UTF8( *name ) ).size() > 0;
}

TArray< int > UGameSparksScriptData::GetIntArray( const FString& name ) const
{
    TArray<int> newArray;
    gsstl::vector<int> data = m_Data.GetIntList( TCHAR_TO_UTF8( *name ) );
    for ( gsstl::vector<int>::iterator it = data.begin(); it != data.end(); ++it )
    {
        newArray.Add( *it );
    }
    return newArray;
}

UGameSparksScriptData* UGameSparksScriptData::SetIntArray( const FString& name, const TArray< int > & int_value )
{
    gsstl::vector<int> arrValue;
    for ( int b_arrValue = 0; b_arrValue < int_value.Num(); b_arrValue++ )
    {
        arrValue.push_back( int_value[ b_arrValue ] );
    }
    m_Data.AddNumberList( TCHAR_TO_UTF8( *name ), arrValue );
    return this;
}

const GameSparks::Core::GSRequestData& UGameSparksScriptData::ToRequestData() const
{
    return m_Data;
};

TArray<FString> UGameSparksScriptData::GetKeys() const
{
	gsstl::vector<gsstl::string> keys = m_Data.GetKeys();
	TArray<FString> ukeys;
	for (gsstl::vector<gsstl::string>::iterator it = keys.begin(); it != keys.end(); ++it) {
		ukeys.Add(FString(UTF8_TO_TCHAR(it->c_str())));
	}

	return ukeys;
}
