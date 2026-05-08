// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LInteractInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULInteractInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONROGUELIKE_API ILInteractInterface
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(AActor* Interactor);
};
