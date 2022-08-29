// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/LAIController.h"
#include "Engine\Classes\Kismet\GameplayStatics.h"
#include "BehaviorTree\BlackboardComponent.h"
void ALAIController::BeginPlay()
{
	Super::BeginPlay();
	if (ensureMsgf(BehaviorTree, TEXT("Behavior is nullptr! Please Asign your BehaviorTree in AIController!")))
	{
		RunBehaviorTree(BehaviorTree);

		APawn* MyPawn = UGameplayStatics::GetPlayerPawn(this, 0);

		if (MyPawn)
		{
			//GetBlackboardComponent()->SetValueAsVector("MoveToLocation", MyPawn->GetActorLocation());
			GetBlackboardComponent()->SetValueAsObject("TargetActor", MyPawn);

		}
	}
	
}

