// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PotionBase.h"
#include "LGameplayInterface.h"
#include "LHealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ALHealthPotion : public APotionBase,public ILGameplayInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float HealAmount;

public:
	ALHealthPotion();
	void Interact_Implementation(APawn* InstigatorPawn);
	
};
