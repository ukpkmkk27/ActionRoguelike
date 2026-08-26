// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUp/LDataAsset_StartUpDataBase.h"
#include "LDataAsset_EnemyStartUpData.generated.h"

/**
 * 
 */
class ULEnemyGameplayAbility;
class ULAbilitySystemComponent;
UCLASS()
class ACTIONROGUELIKE_API ULDataAsset_EnemyStartUpData : public ULDataAsset_StartUpDataBase
{
	GENERATED_BODY()
public:
	virtual void GiveToAbilitySystemComponent(ULAbilitySystemComponent* InASCToGive, int32 ApplyInLevel = 1) override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<ULEnemyGameplayAbility>> EnemyStartUpAbilitySet;
};
