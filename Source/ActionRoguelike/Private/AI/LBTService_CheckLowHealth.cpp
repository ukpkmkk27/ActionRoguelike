// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/LBTService_CheckLowHealth.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "AIController.h"
#include "BehaviorTree\BehaviorTreeTypes.h"
#include "AI/LAICharacter.h"
#include "LAttributeComponent.h"

void ULBTService_CheckLowHealth::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	//Check it has been Low Health State;
	AAIController* AIC = OwnerComp.GetAIOwner();
	UBlackboardComponent* BBC = OwnerComp.GetBlackboardComponent();
	if (ensure(AIC))
	{
		ALAICharacter* AICharacter = Cast<ALAICharacter>(AIC->GetPawn());
		if (ensure(AICharacter))
		{
			//there has A Wrong  
			ULAttributeComponent* AttributeComp = ULAttributeComponent::GetAttributeComp(AICharacter);
			bool UnderLow = AttributeComp->GetHealth() < LowHealthLine;
			BBC->SetValueAsBool(LowHealthKey.SelectedKeyName, UnderLow);
		}

	}
}
