// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/LBTTask_SelfCure.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "AI/LAICharacter.h"
#include "AIController.h"
#include "LAttributeComponent.h"
EBTNodeResult::Type ULBTTask_SelfCure::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Self Cure!!
	AAIController* AIC = OwnerComp.GetAIOwner();
	if (ensure(AIC))
	{	
		ALAICharacter* AICharacter = Cast<ALAICharacter>(AIC->GetPawn());
		UBlackboardComponent* BBC = OwnerComp.GetBlackboardComponent();
		if (ensure(AICharacter))
		{
			ULAttributeComponent* AttributeComp = Cast<ULAttributeComponent>(AICharacter->GetComponentByClass(ULAttributeComponent::StaticClass()));
			AttributeComp->ApplyHealthChange(AICharacter,100);
			return EBTNodeResult::Succeeded;
		}
		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Failed;
}
