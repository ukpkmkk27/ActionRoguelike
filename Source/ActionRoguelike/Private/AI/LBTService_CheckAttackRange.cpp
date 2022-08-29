// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/LBTService_CheckAttackRange.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "AIController.h"
#include "BehaviorTree\BehaviorTreeTypes.h"
void ULBTService_CheckAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp,NodeMemory,DeltaSeconds);
	//Check distance between TargetActor and AI
	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (ensure(Blackboard))
	{
		AActor* TargetActor =Cast<AActor>(Blackboard->GetValueAsObject("TargetActor"));
		if (TargetActor)
		{
			AAIController* AIController =OwnerComp.GetAIOwner();
			if (ensure(AIController))
			{
				APawn* AIPawn = AIController->GetPawn();
				if (ensure(AIPawn))
				{
					float DistanceTo = FVector::Distance(AIPawn->GetActorLocation(), TargetActor->GetActorLocation());
					
					bool bWithinRange = DistanceTo < 2000.f;
					
					bool IsVisible = false;

					if (bWithinRange)
					{
						IsVisible = AIController->LineOfSightTo(TargetActor);
					}
					
					Blackboard->SetValueAsBool(AttackRangeKey.SelectedKeyName, (IsVisible&&bWithinRange));
				}
				
			}
			
		}
	}

}
