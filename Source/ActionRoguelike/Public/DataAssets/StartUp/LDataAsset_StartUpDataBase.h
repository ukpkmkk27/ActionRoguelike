// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LDataAsset_StartUpDataBase.generated.h"

class ULGameplayAbility;
class ULAbilitySystemComponent;
class UGameplayEffect;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ULDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(ULAbilitySystemComponent* InASCToGive, int32 ApplyInLevel = 1);
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<ULGameplayAbility>> ActivateOnGivenAbilities;
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<ULGameplayAbility>> ReactiveAbilities;
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UGameplayEffect>> StartUpGameplayEffects;
	
	void GrantAbilities(const TArray<TSubclassOf<ULGameplayAbility>>& InAbilitiesToGive, ULAbilitySystemComponent* InASCToGive, int32 ApplyInLevel = 1);
};
