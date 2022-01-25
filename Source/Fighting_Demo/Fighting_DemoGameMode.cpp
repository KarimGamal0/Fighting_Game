// Copyright Epic Games, Inc. All Rights Reserved.

#include "Fighting_DemoGameMode.h"
#include "Fighting_DemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFighting_DemoGameMode::AFighting_DemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
