// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "LBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "LHeroCharacter.generated.h"


/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ALHeroCharacter : public ALBaseCharacter
{
	GENERATED_BODY()
public:
	ALHeroCharacter();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Move X and Y
	void MoveForward(float Value);
	void MoveRight(float Value);

	// Control View Direction
	void Turn(float Value);
	void LookUp(float Value);

	// Control Hero Jump
	//virtual void Jump() override;
	//virtual void StopJumping() override;


};
