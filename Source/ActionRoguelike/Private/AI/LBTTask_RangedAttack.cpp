// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/LBTTask_RangedAttack.h"
#include "AIController.h"
#include "BehaviorTree\BlackboardComponent.h"
#include "AI/LAICharacter.h"
#include "LAttributeComponent.h"

ULBTTask_RangedAttack::ULBTTask_RangedAttack()
{
	MaxBulletSpread = 2.0f;
}


EBTNodeResult::Type ULBTTask_RangedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AiController = OwnerComp.GetAIOwner();
	if (ensure(AiController))
	{
		ALAICharacter* AiCharacter = Cast<ALAICharacter>(AiController->GetPawn());
		if (AiCharacter == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		FVector MuzzleLocation = AiCharacter->GetMesh()->GetSocketLocation("Muzzle_01");

		AActor* TargetActor = Cast<AActor>(AiController->GetBlackboardComponent()->GetValueAsObject("TargetActor"));

		if (TargetActor == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		if (!ULAttributeComponent::IsAliveActor(TargetActor))
		{
			return EBTNodeResult::Failed;
		}

		FVector Direction = TargetActor->GetActorLocation() - MuzzleLocation;
		FRotator MuzzleRotation = Direction.Rotation();
		MuzzleRotation.Pitch += FMath::RandRange(0.f,MaxBulletSpread);
		MuzzleRotation.Yaw += FMath::RandRange(-MaxBulletSpread, MaxBulletSpread);

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ActorSpawnParams.Instigator = AiCharacter;
		AActor* SpawnActor = GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzleLocation, MuzzleRotation, ActorSpawnParams);

		return SpawnActor ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;
	}
	 
	return EBTNodeResult::Failed;

}

