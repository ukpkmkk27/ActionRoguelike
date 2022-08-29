// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LAIController.generated.h"

class UBehaviorTree;
/**
 * 
 */
UCLASS() 
class ACTIONROGUELIKE_API ALAIController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
public:

	 
};
