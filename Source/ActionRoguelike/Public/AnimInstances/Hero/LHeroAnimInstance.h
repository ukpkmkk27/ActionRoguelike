// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/LCharacterAnimInstance.h"
#include "LHeroAnimInstance.generated.h"

class ALHeroCharacter;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ULHeroAnimInstance : public ULCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation_WorkerThread(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	ALHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float EnterRelaxThreshold = 5.f;

	float RelaxElapsedTime;


};
