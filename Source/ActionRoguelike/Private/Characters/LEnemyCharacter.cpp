// Yujiang Li All Rights Reserved


#include "Characters/LEnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Combat/EnemyCombatComponent.h"
#include "Engine/AssetManager.h"
#include "DataAssets/StartUp/LDataAsset_EnemyStartUpData.h"
#include "LDebugHelper.h"

ALEnemyCharacter::ALEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));
}

UPawnCombatComponent* ALEnemyCharacter::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

void ALEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (CharacterStartUpData.IsNull()) return;

	UAssetManager::GetStreamableManager().RequestAsyncLoad(CharacterStartUpData.ToSoftObjectPath(), 
		FStreamableDelegate::CreateLambda(
			[this]() 
			{
				ULDataAsset_StartUpDataBase* LoadData = CharacterStartUpData.Get();
				LoadData->GiveToAbilitySystemComponent(LAbilitySystemComponent);
			}
		)
	);

}