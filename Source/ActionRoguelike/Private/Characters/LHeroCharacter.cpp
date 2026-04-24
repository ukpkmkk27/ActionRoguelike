// Yujiang Li All Rights Reserved


#include "Characters/LHeroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "LDebugHelper.h"

ALHeroCharacter::ALHeroCharacter()
{
	bUseControllerRotationYaw = false;

	// Created and Fixed CamereBoom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->SocketOffset = FVector(0.0f, -45.0f, 90.0f);
	CameraBoom->bUsePawnControlRotation = true;

	// Created and Fixed Camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	//
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);


}

void ALHeroCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// Bind Axis 
	PlayerInputComponent->BindAxis("MoveForward", this, &ALHeroCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALHeroCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ALHeroCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &ALHeroCharacter::Turn);
	// Bind Action
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ALHeroCharacter::Jump);
	PlayerInputComponent->BindAction("Jump",IE_Released, this, &ALHeroCharacter::StopJumping);

}

void ALHeroCharacter::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.0f)
	{
		FRotator Rotation = Controller->GetControlRotation();

		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, Value);

	}
}

void ALHeroCharacter::MoveRight(float Value)
{
	if (Controller != nullptr && Value != 0.0f)
	{
		FRotator Rotation = Controller->GetControlRotation();

		const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, Value);

	}
}

void ALHeroCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ALHeroCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ALHeroCharacter::Jump()
{
	Super::Jump();
}

void ALHeroCharacter::StopJumping()
{
	Super::StopJumping();
}


