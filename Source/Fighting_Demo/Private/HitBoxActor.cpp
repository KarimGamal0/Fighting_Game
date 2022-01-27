// Fill out your copyright notice in the Description page of Project Settings.


#include "HitBoxActor.h"

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
		break;

	case EHitboxEnum::HB_STRIKE:
		HitboxDisplay->SetMaterial(0, Strike_Material);
		HitboxDisplay->SetWorldLocation(HitboxLocation);
		HitboxDisplay->SetVisibility(true);
		break;

	case EHitboxEnum::HB_HURTBOX:
		HitboxDisplay->SetMaterial(0, Hurt_Material);
		HitboxDisplay->SetWorldLocation(HitboxLocation);
		HitboxDisplay->SetVisibility(true);
		break;

	}
}


