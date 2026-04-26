// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/LDataAsset_InputConfig.h"
#include "LDebugHelper.h"

#include "LInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ULInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:

	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const ULDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};

template<class UserObject, typename CallbackFunc>
inline void ULInputComponent::BindNativeInputAction(const ULDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("InputConfig Is Null, Can Not Process With Binding"));

	if (UInputAction* FoundAction = InInputConfig->FindNativeActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}

}