// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class ALHeroWeapon;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
protected:
	UFUNCTION(BlueprintCallable, Category = "L|Combat")
	ALHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;
};
