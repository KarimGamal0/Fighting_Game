// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitBoxActor.generated.h"

UENUM(BlueprintType)
enum class EHitboxEnum : uint8
{
	HB_PROXIMITY UMETA(DisplayName = "Proximity"),
	HB_STRIKE UMETA(DisplayName = "Strike"),
	HB_HURTBOX UMETA(DisplayName = "Hurtbox")
};

UCLASS()
class FIGHTING_DEMO_API AHitBoxActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Sets default values for this actor's properties
	AHitBoxActor();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* HitboxDisplay;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
		USceneComponent* SceneComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
		EHitboxEnum HitboxType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hitbox")
		FVector HitboxLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Materials")
		UMaterialInterface* Proximity_Material;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Materials")
		UMaterialInterface* Strike_Material;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Materials")
		UMaterialInterface* Hurt_Material;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void TriggerVisualizeHitBox();

	UFUNCTION(BlueprintImplementableEvent)
		void VisualizeHitBox();

	UFUNCTION(BlueprintCallable)
		void SpawnHitbox();
};
