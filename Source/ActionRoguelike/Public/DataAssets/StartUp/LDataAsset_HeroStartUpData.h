// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUp/LDataAsset_StartUpDataBase.h"
#include "LTypes/LStructTypes.h"
#include "LDataAsset_HeroStartUpData.generated.h"


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
