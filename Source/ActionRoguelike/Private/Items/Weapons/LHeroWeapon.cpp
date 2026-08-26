// Yujiang Li All Rights Reserved


#include "Items/Weapons/LHeroWeapon.h"


void ALHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InGrantedAbilityHandles)
{
    GrantedAbilityHandles = InGrantedAbilityHandles;
}

TArray<FGameplayAbilitySpecHandle> ALHeroWeapon::GetGrantedAbilitySpecHandles() const
{
    return GrantedAbilityHandles;
}
