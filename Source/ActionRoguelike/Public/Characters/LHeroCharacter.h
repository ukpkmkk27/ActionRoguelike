// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "LBaseCharacter.h"

#include "LHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ULDataAsset_InputConfig;
struct FInputActionValue;
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
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* FollowCamera;

#pragma endregion

#pragma region Input

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	ULDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
	void Input_Jump(const FInputActionValue& InputActionValue);


#pragma endregion


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




};
