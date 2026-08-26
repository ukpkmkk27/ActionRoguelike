// Yujiang Li All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/LHeroWeapon.h"

ALHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	return Cast<ALHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTagToGet));
}