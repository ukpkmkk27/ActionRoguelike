// Yujiang Li All Rights Reserved


#include "AbilitySystem/LAbilitySystemComponent.h"

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
