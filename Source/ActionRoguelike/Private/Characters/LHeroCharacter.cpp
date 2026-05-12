// Yujiang Li All Rights Reserved


#include "Characters/LHeroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAssets/Input/LDataAsset_InputConfig.h"
#include "Components/Input/LInputComponent.h"
#include "Interfaces/LInteractInterface.h"
#include "LGameplayTags.h"
#include "AbilitySystem/LAbilitySystemComponent.h"
#include "DataAssets/StartUp/LDataAsset_HeroStartUpData.h"
#include "Components/Combat/HeroCombatComponent.h"

#include "DrawDebugHelpers.h"
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
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	//
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));



}

void ALHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset,TEXT("Forgot to assign a valid data asset to input config."))

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);
	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultInputMappingContext, 0);

	ULInputComponent* LInputComponent =  CastChecked<ULInputComponent>(PlayerInputComponent);
	LInputComponent->BindNativeInputAction(InputConfigDataAsset, LGamePlayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ALHeroCharacter::Input_Move);
	LInputComponent->BindNativeInputAction(InputConfigDataAsset, LGamePlayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ALHeroCharacter::Input_Look);
	LInputComponent->BindNativeInputAction(InputConfigDataAsset, LGamePlayTags::InputTag_Jump, ETriggerEvent::Triggered, this, &ALHeroCharacter::Input_Jump);
	LInputComponent->BindNativeInputAction(InputConfigDataAsset, LGamePlayTags::InputTag_Interact, ETriggerEvent::Triggered, this, &ALHeroCharacter::Input_Interact);
	

}


void ALHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (!CharacterStartUpData.IsNull())
	{
		if (ULDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(LAbilitySystemComponent);
		}
	}
	//if (LAbilitySystemComponent && LAttributeSet)
	//{
	//	const FString ASCText = FString::Printf(TEXT("OwnerActor: %s, AvatarActor: %s"), *LAbilitySystemComponent->GetOwnerActor()->GetActorLabel(), *LAbilitySystemComponent->GetAvatarActor()->GetActorLabel());
	//	Debug::Print(TEXT("AbilitySystemComponent valid." + ASCText), FColor::Green);
	//	Debug::Print(TEXT("AttributeSet valid." + ASCText), FColor::Green);
	//}
}

void ALHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator YawRotation = FRotator(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
	
	if (MovementVector.Y != 0)
	{
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		
		AddMovementInput(ForwardDirection, MovementVector.Y);

	}
	if (MovementVector.X != 0)
	{
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ALHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();
	if (LookAxisVector.X != 0)
	{

		AddControllerYawInput(LookAxisVector.X);

	}
	if (LookAxisVector.Y != 0)
	{
		AddControllerPitchInput(-LookAxisVector.Y);
	}
}

void ALHeroCharacter::Input_Jump(const FInputActionValue& InputActionValue)
{
	bool bIsJump = InputActionValue.Get<bool>();
	if (bIsJump)
	{
		Jump();
	}
}

void ALHeroCharacter::Input_Interact(const FInputActionValue& InputActionValue)
{
	bool bIsInteract = InputActionValue.Get<bool>();
	if (bIsInteract)
	{
		APlayerController* PC = GetController<APlayerController>();
		if (PC)
		{
			int32 Width, Height;
			PC->GetViewportSize(Width, Height);
			FVector StartLocation, StartDirection;
			bool bPoject = PC->DeprojectScreenPositionToWorld(Width / 2.0f, Height / 2.0f, StartLocation, StartDirection);
			FVector EndLocation = StartLocation + StartDirection * 1000;

			FHitResult HitResult;
			FCollisionQueryParams QueryParams;
			QueryParams.AddIgnoredActor(this);
			GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, QueryParams);
			if (AActor* HitActor =  HitResult.GetActor())
			{
				if (HitActor->Implements<ULInteractInterface>())
				{
					ILInteractInterface::Execute_Interact(HitActor, this);
				}
			}

		}


	}
}



