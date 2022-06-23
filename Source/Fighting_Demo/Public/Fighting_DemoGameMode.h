// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Fighting_DemoGameMode.generated.h"

class AFighting_DemoCharacter;

UCLASS(minimalapi)
class AFighting_DemoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFighting_DemoGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerReferences")
		AFighting_DemoCharacter* Player1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerReferences")
		AFighting_DemoCharacter* Player2;

	UFUNCTION(Blueprintcallable)
		void SpawnPlayers(UObject* object);

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AFighting_DemoCharacter> CharacterClass;

protected:

	virtual void BeginPlay() override;


};



