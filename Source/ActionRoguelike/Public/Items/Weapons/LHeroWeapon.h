// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/LWeaponBase.h"
#include "LTypes/LStructTypes.h"
#include "GameplayAbilitySpec.h"
#include "LHeroWeapon.generated.h"



/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ALHeroWeapon : public ALWeaponBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories = "WeaponData"))
	FLHeroWeaponData HeroWeaponData;
	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InGrantedAbilityHandles);
	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;


private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilityHandles;

};
