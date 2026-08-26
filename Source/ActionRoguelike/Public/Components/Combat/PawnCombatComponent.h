// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class ALWeaponBase;
/**
 * 
 */
UENUM(BlueprintType)
enum class EToggleCollisionType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand
};

UCLASS()
class ACTIONROGUELIKE_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

private:
	TMap<FGameplayTag, ALWeaponBase*> CharacterCarriedWeaponMap;
protected:
	UFUNCTION(BlueprintCallable, Category = "L|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ALWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable,Category = "L|Combat")
	ALWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "L|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "L|Combat")
	ALWeaponBase* GetCurrentCharacterEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "L|Combat")
	void ToggleWeaponCollision(bool bEnableCollision, EToggleCollisionType ToggleCollisionType);
};
