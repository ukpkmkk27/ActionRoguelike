// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EnvironmentQuery\EnvQueryTypes.h"
#include "LGameModeBase.generated.h"

/**
 * 
 */
class UEnvQuery;
class UEnvQueryInstanceBlueprintWrapper;
UCLASS()
class ACTIONROGUELIKE_API ALGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ALGameModeBase();

	virtual void StartPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TSubclassOf<AActor> MinionClass;

	UPROPERTY(EditDefaultsOnly,Category = "AI")
	UEnvQuery* SpawnBotQuery;
	
	FTimerHandle TimerHandle_SpawnBot;
	
	UPROPERTY(EditDefaultsOnly,Category = "AI")
	float Delay;

	UFUNCTION()
	void OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus);

	void SpawnBotTimerElapsed();
};
