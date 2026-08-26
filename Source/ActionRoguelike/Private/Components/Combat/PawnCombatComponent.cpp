// Yujiang Li All Rights Reserved


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/LWeaponBase.h"
#include "LDebugHelper.h"
#include "Components/BoxComponent.h"
void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ALWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A tag named: %s has already added as carried weapon map"),*InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);
	
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
	if (bRegisterAsEquippedWeapon) CurrentEquippedWeaponTag = InWeaponTagToRegister;

}

ALWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (ALWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}

	return nullptr;
}

ALWeaponBase* UPawnCombatComponent::GetCurrentCharacterEquippedWeapon() const
{
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UPawnCombatComponent::ToggleWeaponCollision(bool bEnableCollision, EToggleCollisionType ToggleCollisionType)
{
	if (ToggleCollisionType == EToggleCollisionType::CurrentEquippedWeapon)
	{
		ALWeaponBase* CurrentWeapon = GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
		if (CurrentWeapon)
		{
			if (bEnableCollision)
			{
				CurrentWeapon->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			}
			else
			{
				CurrentWeapon->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			}
		}

	}
}