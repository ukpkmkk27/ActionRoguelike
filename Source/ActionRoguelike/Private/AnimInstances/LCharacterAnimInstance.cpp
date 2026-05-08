// Yujiang Li All Rights Reserved


#include "AnimInstances/LCharacterAnimInstance.h"
#include "Characters/LBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ULCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ALBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}

}

void ULCharacterAnimInstance::NativeUpdateAnimation_WorkerThread(float DeltaSeconds)
{
	if (!OwningCharacter || !OwningMovementComponent) return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared() > 0.f;
	bIsFalling = OwningMovementComponent->IsFalling();
}
