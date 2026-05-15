// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"

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
	
};
