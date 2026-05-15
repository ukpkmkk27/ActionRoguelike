// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "LDataAsset_InputConfig.generated.h"


class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FLInputConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	UInputAction* InputAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag GameplayTag;

	bool IsValid() const
	{
		return GameplayTag.IsValid() && InputAction;
	}
};

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ULDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta = (TitleProperty= "GameplayTag"))
	TArray<FLInputConfig> NativeInputActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "GameplayTag"))
	TArray<FLInputConfig> GameAbilityInputActions;

	UInputAction* FindNativeActionByTag(const FGameplayTag& InGameplayTag) const;

};
