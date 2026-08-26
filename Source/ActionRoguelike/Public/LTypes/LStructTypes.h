// Yujiang Li All Rights Reserved

#pragma once
#include "GameplayTagContainer.h"
#include "LStructTypes.generated.h"

class ULHeroGameplayAbility;
class ULHeroLinkedAnimLayer;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FLHeroAbilityConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULHeroGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FLHeroWeaponData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "WeaponData"))
	TSubclassOf<ULHeroLinkedAnimLayer> WeaponAnimLayerSubclassToLink;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* WeaponInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FLHeroAbilityConfig> WeaponAbilitiesToGrant;


};