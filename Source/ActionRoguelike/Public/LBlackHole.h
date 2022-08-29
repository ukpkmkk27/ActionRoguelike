// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileBase.h"
#include "LBlackHole.generated.h"

/**
 * 
 */
class URadialForceComponent;
UCLASS()
class ACTIONROGUELIKE_API ALBlackHole : public AProjectileBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	URadialForceComponent* PullForcecomp;

public:
	ALBlackHole();
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
