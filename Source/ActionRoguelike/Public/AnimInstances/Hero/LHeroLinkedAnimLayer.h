// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/LBaseAnimInstance.h"
#include "LHeroLinkedAnimLayer.generated.h"

class ULHeroAnimInstance;

UCLASS()
class ACTIONROGUELIKE_API ULHeroLinkedAnimLayer : public ULBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (BlueprintThreadSafe))
	ULHeroAnimInstance* GetHeroAnimInstance() const;
};
