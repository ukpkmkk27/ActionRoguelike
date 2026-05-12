// Yujiang Li All Rights Reserved


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/LWeaponBase.h"
#include "LDebugHelper.h"
void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ALWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A tag named: %s has already added as carried weapon map"),*InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);
	
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
	if (bRegisterAsEquippedWeapon) CurrentEquippedWeaponTag = InWeaponTagToRegister;
	const FString WeaponMsg = FString::Printf(TEXT("A weapon named: %s has been registered by tag: %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	Debug::Print(WeaponMsg);
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
