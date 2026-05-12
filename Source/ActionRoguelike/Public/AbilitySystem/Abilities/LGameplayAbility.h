// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "LGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class ELAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};


class UPawnCombatComponent;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ULGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly,Category = "LAbility")
	ELAbilityActivationPolicy AbilityActivationPolicy = ELAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "L|Combat")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;
	
};
