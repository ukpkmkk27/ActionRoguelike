// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/LGameplayAbility.h"
#include "LEnemyGameplayAbility.generated.h"

/**
 * 
 */
class ALEnemyCharacter;
class UEnemyCombatComponent;
UCLASS()
class ACTIONROGUELIKE_API ULEnemyGameplayAbility : public ULGameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, Category = "L|GameAbility")
	ALEnemyCharacter* GetEnemyCharacterFromActorInfo();	
	
	UFUNCTION(BlueprintPure, Category = "L|GameAbility")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ALEnemyCharacter> CachedOwningEnemyCharacter;

};
