// Yujiang Li All Rights Reserved


#include "AbilitySystem/Abilities/LEnemyGameplayAbility.h"
#include "Characters/LEnemyCharacter.h"
ALEnemyCharacter* ULEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedOwningEnemyCharacter.IsValid())
	{
		CachedOwningEnemyCharacter = Cast<ALEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}
	return CachedOwningEnemyCharacter.IsValid() ? CachedOwningEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* ULEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyConbatComponent();
}
