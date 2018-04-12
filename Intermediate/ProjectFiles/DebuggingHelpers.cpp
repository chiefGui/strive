#include "DebuggingHelpers.h"
#include <Engine/Engine.h>

void DebuggingHelpers::PrintString(FString Message)
{
	GEngine->AddOnScreenDebugMessage(
		-1
		, 1.f
		, FColor::Cyan
		, Message
	);
}
