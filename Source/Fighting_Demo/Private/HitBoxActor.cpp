// Fill out your copyright notice in the Description page of Project Settings.


#include "HitBoxActor.h"
#include "Kismet/GameplayStatics.h" 
#include "GameFramework/Character.h" 
#include "Fighting_DemoCharacter.h"

// Sets default values
AHitBoxActor::AHitBoxActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	SetRootComponent(SceneComponent);
	//RootComponent = SceneComponent;

	HitboxDisplay = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	HitboxDisplay->SetupAttachment(RootComponent);

	HitboxDamage = 0.0f;
}

// Called when the game starts or when spawned
void AHitBoxActor::BeginPlay()
{
	Super::BeginPlay();

	if (!Proximity_Material || !Strike_Material || !Hurt_Material) {
		UE_LOG(LogTemp, Error, TEXT("Material doesn't Exist"));
		return;
	}
}

// Called every frame
void AHitBoxActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHitBoxActor::TriggerVisualizeHitBox()
{
	VisualizeHitBox();
}

void AHitBoxActor::SpawnHitbox()
{
	switch (HitboxType)
	{

	case EHitboxEnum::HB_PROXIMITY:
		HitboxDisplay->SetMaterial(0, Proximity_Material);
		HitboxDisplay->SetWorldLocation(HitboxLocation);
		HitboxDisplay->SetVisibility(true);
		CheckCollision();
		break;

	case EHitboxEnum::HB_STRIKE:
		HitboxDisplay->SetMaterial(0, Strike_Material);
		HitboxDisplay->SetWorldLocation(HitboxLocation);
		HitboxDisplay->SetVisibility(true);
		CheckCollision();
		break;

	case EHitboxEnum::HB_HURTBOX:
		HitboxDisplay->SetMaterial(0, Hurt_Material);
		HitboxDisplay->SetWorldLocation(HitboxLocation);
		HitboxDisplay->SetVisibility(true);
		CheckCollision();
		break;
	}
}

void AHitBoxActor::CheckCollision()
{

	AActor* OverlappingActor = Cast<AActor>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//UE_LOG(LogTemp, Error, TEXT(" dsadsa %s"), *OverlappingActor->GetName());

	if (!OverlappingActor)
	{
		//UE_LOG(LogTemp, Error, TEXT(" dsadsa %s"), *OverlappingActor->GetName());
		UE_LOG(LogTemp, Error, TEXT("There is no character in the level"));
		return;
	}

	if (IsOverlappingActor(OverlappingActor)) {
		AFighting_DemoCharacter* Character = Cast<AFighting_DemoCharacter>(OverlappingActor);

		if (!Character) {
			UE_LOG(LogTemp, Error, TEXT("The Overlapping actor is not a character"));
			return;
		}

		UE_LOG(LogTemp, Error, TEXT("Damage"));
		Character->TakeDamage(HitboxDamage);
	}

}


