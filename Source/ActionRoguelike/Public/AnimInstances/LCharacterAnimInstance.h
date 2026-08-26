// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/LBaseAnimInstance.h"
#include "LCharacterAnimInstance.generated.h"

/**
 * 
 */
class ALBaseCharacter;
class UCharacterMovementComponent;
UCLASS()
class ACTIONROGUELIKE_API ULCharacterAnimInstance : public ULBaseAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation_WorkerThread(float DeltaSeconds) override;
public:
	UPROPERTY()
	ALBaseCharacter* OwningCharacter;
	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly,Category="AnimData|LocomotionData")
	float GroundSpeed;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bIsFalling;

};
