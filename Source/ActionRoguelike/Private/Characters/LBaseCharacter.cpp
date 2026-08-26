// Yujiang Li All Rights Reserved


#include "Characters/LBaseCharacter.h"
#include "AbilitySystem/LAbilitySystemComponent.h"
#include "AbilitySystem/LAttributeSet.h"

ALBaseCharacter::ALBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->bReceivesDecals = false;

	LAbilitySystemComponent = CreateDefaultSubobject<ULAbilitySystemComponent>(TEXT("LAbilitySystemComponent"));
	LAttributeSet = CreateDefaultSubobject<ULAttributeSet>(TEXT("LAttributeSet"));

	 
}

UAbilitySystemComponent* ALBaseCharacter::GetAbilitySystemComponent() const
{
	return GetLAbilitySystemComponent();
}

UPawnCombatComponent* ALBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

void ALBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (LAbilitySystemComponent)
	{
		LAbilitySystemComponent->InitAbilityActorInfo(this, this);
		//ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("Forget to assign Character StartUp Data: %s"), *GetName());
	}
}
