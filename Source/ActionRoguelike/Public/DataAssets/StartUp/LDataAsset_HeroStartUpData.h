// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUp/LDataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "LDataAsset_HeroStartUpData.generated.h"


class ULGameplayAbility;

USTRUCT(BlueprintType)
struct FLHeroAbilityConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag GameplayTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ULDataAsset_HeroStartUpData : public ULDataAsset_StartUpDataBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "GameplayTag"))
	TArray<FLHeroAbilityConfig> HeroStartUpAbilitySet;

public:
	virtual void GiveToAbilitySystemComponent(ULAbilitySystemComponent* InASCToGive, int32 ApplyInLevel = 1) override;
};
