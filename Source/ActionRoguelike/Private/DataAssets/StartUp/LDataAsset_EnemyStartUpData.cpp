// Yujiang Li All Rights Reserved


#include "DataAssets/StartUp/LDataAsset_EnemyStartUpData.h"
#include "AbilitySystem/Abilities/LEnemyGameplayAbility.h"
#include "AbilitySystem/LAbilitySystemComponent.h"

void ULDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(ULAbilitySystemComponent* InASCToGive, int32 ApplyInLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyInLevel);

	if (EnemyStartUpAbilitySet.Num()!=0)
	{
		for (const TSubclassOf<ULEnemyGameplayAbility>& EnemyAbilityClass : EnemyStartUpAbilitySet)
		{
			FGameplayAbilitySpec AbilitySpec(EnemyAbilityClass);
			AbilitySpec.SourceObject = InASCToGive->AvatarActor;
			AbilitySpec.Level = ApplyInLevel;
			InASCToGive->GiveAbility(AbilitySpec);
		}

	}
}