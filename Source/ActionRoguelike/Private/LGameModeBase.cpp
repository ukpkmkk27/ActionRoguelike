// Fill out your copyright notice in the Description page of Project Settings.


#include "LGameModeBase.h"
#include "EnvironmentQuery\EnvQueryManager.h"
#include "EnvironmentQuery\EnvQueryTypes.h"
#include "EnvironmentQuery\EnvQueryInstanceBlueprintWrapper.h"
#include "AI/LAICharacter.h"
#include "Engine\Public\EngineUtils.h"
#include "LAttributeComponent.h"
ALGameModeBase::ALGameModeBase()
{
	Delay = 2.0f;
}

void ALGameModeBase::StartPlay()
{
	Super::StartPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_SpawnBot, this, &ALGameModeBase::SpawnBotTimerElapsed, Delay, true);
}

void ALGameModeBase::SpawnBotTimerElapsed()
{
	int32 NrOfAliveBots = 0;
	for (TActorIterator<ALAICharacter> It(GetWorld()); It; ++It)
	{
		ALAICharacter* Bot = *It;
		ULAttributeComponent* AttributeComp = Cast<ULAttributeComponent>(Bot->GetComponentByClass(ULAttributeComponent::StaticClass()));
		if (AttributeComp && AttributeComp->IsAlive())
		{
			NrOfAliveBots++;
		}
	}
	const int MaxCount = 1;
	if (NrOfAliveBots >= MaxCount)
	{
		return;
	}

	UEnvQueryInstanceBlueprintWrapper* QueryInstance = UEnvQueryManager::RunEQSQuery(this, SpawnBotQuery, this, EEnvQueryRunMode::RandomBest5Pct, nullptr);
	if (ensure(QueryInstance))
	{
		QueryInstance->GetOnQueryFinishedEvent().AddDynamic(this, &ALGameModeBase::OnQueryCompleted);
	}
	
}

void ALGameModeBase::OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus)
{
	if (QueryStatus != EEnvQueryStatus::Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn Bot Query Failed!"));
		return;
	}

	
	TArray<FVector> Locations = QueryInstance->GetResultsAsLocations();
	if (Locations.IsValidIndex(0))
	{
		GetWorld()->SpawnActor<AActor>(MinionClass, Locations[0], FRotator::ZeroRotator);
	}
}
