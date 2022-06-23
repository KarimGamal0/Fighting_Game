// Copyright Epic Games, Inc. All Rights Reserved.

#include "Fighting_DemoGameMode.h"
#include "Fighting_DemoCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h" 

AFighting_DemoGameMode::AFighting_DemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}


void AFighting_DemoGameMode::BeginPlay()
{
	Super::BeginPlay();


	TArray<AActor*> PlayerStarts;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), PlayerStarts);

	for (AActor* Actor : PlayerStarts) {


		APlayerStart* PlayerStart = Cast<APlayerStart>(Actor);
		if (PlayerStart) {
			SpawnPlayers(PlayerStart);
		}


	}
}

void AFighting_DemoGameMode::SpawnPlayers(UObject* object)
{
	APlayerStart* PlayerStart = Cast<APlayerStart>(object);

	if (!PlayerStart) {
		return;
	}

	FActorSpawnParameters SpawnParams;
	if (PlayerStart->PlayerStartTag == "P1") {
		Player1 = GetWorld()->SpawnActor<AFighting_DemoCharacter>(CharacterClass, PlayerStart->GetActorTransform(), SpawnParams);
	}
	else if (PlayerStart->PlayerStartTag == "P2") {
		Player2 = GetWorld()->SpawnActor<AFighting_DemoCharacter>(CharacterClass, PlayerStart->GetActorTransform(), SpawnParams);
	}

}

