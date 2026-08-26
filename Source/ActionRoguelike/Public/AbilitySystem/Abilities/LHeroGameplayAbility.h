// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/LGameplayAbility.h"
#include "LHeroGameplayAbility.generated.h"

class ALHeroCharacter;
class ALHeroPlayerController;
class ULAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ULHeroGameplayAbility : public ULGameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "L|GameAbility")
	ALHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "L|GameAbility")
	ALHeroPlayerController* GetHeroPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "L|GameAbility")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "L|GameAbility")
	ULAbilitySystemComponent* GetLAbilitySystemComponentFromActorInfo();

private:
	TWeakObjectPtr<ALHeroCharacter> CachedOwningHeroCharacter;
	TWeakObjectPtr<ALHeroPlayerController> CachedOwningHeroPlayerController;
};
