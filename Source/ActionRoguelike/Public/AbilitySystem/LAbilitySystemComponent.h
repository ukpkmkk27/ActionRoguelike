// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "LTypes/LStructTypes.h"

#include "LAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ULAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);
	
	UFUNCTION(BlueprintCallable, Category = "L|GameAbility",meta = (ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FLHeroAbilityConfig>& InDefaultWeaponAbilites, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle);
		
	UFUNCTION(BlueprintCallable, Category = "L|GameAbility")
	void RemoveHeroWeaponAbilities(UPARAM(ref)TArray<FGameplayAbilitySpecHandle>& InGrantedAbilitySpecHandle);
	
};
