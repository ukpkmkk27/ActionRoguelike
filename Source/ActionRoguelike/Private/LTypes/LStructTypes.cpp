// Yujiang Li All Rights Reserved


#include "LTypes/LStructTypes.h"
#include "AbilitySystem/Abilities/LHeroGameplayAbility.h"
bool FLHeroAbilityConfig::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}