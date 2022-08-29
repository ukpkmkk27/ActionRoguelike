// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/LAICharacter.h"
#include "Perception\PawnSensingComponent.h"
#include "AIController.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "LAttributeComponent.h"
#include "BrainComponent.h"
#include "LWorldUserWidget.h"
//#include "AI/LAIController.h"
// Sets default values
ALAICharacter::ALAICharacter()
{
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComp");
	AttributeComp = CreateDefaultSubobject<ULAttributeComponent>("AttributeComp");
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	MaterialName = "TimeToHit";
}

void ALAICharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	PawnSensingComp->OnSeePawn.AddDynamic(this,&ALAICharacter::OnPawnSeen);
	AttributeComp->OnHealthChanged.AddDynamic(this, &ALAICharacter::OnHealthChanged);

}

void ALAICharacter::OnPawnSeen(APawn* Pawn)
{
	SetTargetActor(Pawn);
}

void ALAICharacter::OnHealthChanged(AActor* InstigatorActor, ULAttributeComponent* OwningComp, float NewHealth, float Delta)
{
	if (Delta < 0.0f)
	{
		if (InstigatorActor != this)
		{
			SetTargetActor(InstigatorActor);
		}

		//hit effect
		GetMesh()->SetScalarParameterValueOnMaterials(MaterialName, GetWorld()->TimeSeconds);
		if (ActiveHealthBar == nullptr)
		{
			ActiveHealthBar = CreateWidget<ULWorldUserWidget>(GetWorld(), HealthBarWidgetClass);
			if (ActiveHealthBar)
			{
				ActiveHealthBar->AttachedActor = this;
				ActiveHealthBar->AddToViewport();
			}
		}
		
		if (NewHealth <= 0.0f)
		{
			//stop BT
			AAIController* AIC = Cast<AAIController>(GetController());
			AIC->GetBrainComponent()->StopLogic("Killed");

			//ragdoll
			GetMesh()->SetAllBodiesSimulatePhysics(true);
			GetMesh()->SetCollisionProfileName("Ragdoll");

			//set lifespan
			SetLifeSpan(10.0f);
		}
	}
}

void ALAICharacter::SetTargetActor(AActor* NewTarget)
{
	AAIController* AIC = Cast<AAIController>(GetController());

	AIC->GetBlackboardComponent()->SetValueAsObject("TargetActor", NewTarget);

}

 