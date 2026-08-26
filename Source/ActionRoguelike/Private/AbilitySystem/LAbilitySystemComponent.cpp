// Yujiang Li All Rights Reserved


#include "AbilitySystem/LAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/LHeroGameplayAbility.h"

void ULAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid()) return;

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);

	}
}

void ULAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}


void ULAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FLHeroAbilityConfig>& InDefaultWeaponAbilites, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle)
{
	if (InDefaultWeaponAbilites.Num() == 0) return;

	for (const FLHeroAbilityConfig& HeroAbilityConfig : InDefaultWeaponAbilites)
	{
		if (!HeroAbilityConfig.IsValid()) continue;
		FGameplayAbilitySpec AbilitySpec(HeroAbilityConfig.AbilityToGrant);
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.DynamicAbilityTags.AddTag(HeroAbilityConfig.InputTag);
		OutGrantedAbilitySpecHandle.Add(GiveAbility(AbilitySpec));
	}
}

void ULAbilitySystemComponent::RemoveHeroWeaponAbilities(UPARAM(ref)TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandle)
{
	if (InGrantedAbilitySpecHandle.Num() == 0) return;
	for (const FGameplayAbilitySpecHandle& AbilityHandle : InGrantedAbilitySpecHandle)
	{
		if (AbilityHandle.IsValid())
		{
			ClearAbility(AbilityHandle);
		}
		
	}

	InGrantedAbilitySpecHandle.Empty();
}