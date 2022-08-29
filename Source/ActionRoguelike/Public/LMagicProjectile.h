// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileBase.h"
#include "LMagicProjectile.generated.h"

/**
 * 
 */
class USoundCue;
UCLASS()
class ACTIONROGUELIKE_API ALMagicProjectile : public AProjectileBase
{
	GENERATED_BODY()

public:
	ALMagicProjectile();

protected:
	UPROPERTY(VisibleAnywhere)
	UAudioComponent* AudioComp;
	UPROPERTY()
	USoundCue* HitSound;
	UFUNCTION()
	void OnActorOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(EditAnywhere,Category = "Params")
	float DamageAmount;
};
