// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/LGameplayAbility.h"
#include "LHeroGameplayAbility.generated.h"

class ALHeroCharacter;
class ALHeroPlayerController;
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

private:
	TWeakObjectPtr<ALHeroCharacter> CachedOwningHeroCharacter;
	TWeakObjectPtr<ALHeroPlayerController> CachedOwningHeroPlayerController;
};
