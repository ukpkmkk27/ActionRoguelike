// Yujiang Li All Rights Reserved


#include "AbilitySystem/Abilities/LHeroGameplayAbility.h"
#include "Characters/LHeroCharacter.h"
#include "Controllers/LHeroPlayerController.h"
#include "Components/Combat/HeroCombatComponent.h"

ALHeroCharacter* ULHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedOwningHeroCharacter.IsValid())
	{
		CachedOwningHeroCharacter = Cast<ALHeroCharacter>(CurrentActorInfo->AvatarActor);
		
	}
	return CachedOwningHeroCharacter.IsValid() ? CachedOwningHeroCharacter.Get() : nullptr;
}

ALHeroPlayerController* ULHeroGameplayAbility::GetHeroPlayerControllerFromActorInfo()
{
	if (!CachedOwningHeroPlayerController.IsValid())
	{
		CachedOwningHeroPlayerController = Cast<ALHeroPlayerController>(CurrentActorInfo->PlayerController);

	}
	return CachedOwningHeroPlayerController.IsValid() ? CachedOwningHeroPlayerController.Get() : nullptr;
}

UHeroCombatComponent* ULHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();

}
