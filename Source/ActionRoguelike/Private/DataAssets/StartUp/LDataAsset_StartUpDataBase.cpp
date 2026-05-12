// Yujiang Li All Rights Reserved


#include "DataAssets/StartUp/LDataAsset_StartUpDataBase.h"
#include "AbilitySystem/LAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/LGameplayAbility.h"
#include "LDebugHelper.h"
void ULDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(ULAbilitySystemComponent* InASCToGive, int32 ApplyInLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyInLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyInLevel);

}

void ULDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<ULGameplayAbility>>& InAbilitiesToGive, ULAbilitySystemComponent* InASCToGive, int32 ApplyInLevel)
{
	if (InAbilitiesToGive.Num() == 0)
	{
		return;
	}
	for (const TSubclassOf<ULGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyInLevel;
	
		InASCToGive->GiveAbility(AbilitySpec);
	}
	
}
