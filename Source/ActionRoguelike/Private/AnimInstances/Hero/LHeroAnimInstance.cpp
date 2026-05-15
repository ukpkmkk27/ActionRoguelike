// Yujiang Li All Rights Reserved


#include "AnimInstances/Hero/LHeroAnimInstance.h"
#include "Characters/LHeroCharacter.h"

void ULHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<ALHeroCharacter>(OwningCharacter);
	}
}

void ULHeroAnimInstance::NativeUpdateAnimation_WorkerThread(float DeltaSeconds)
{
	Super::NativeUpdateAnimation_WorkerThread(DeltaSeconds);

	if (bHasAcceleration)
	{
		RelaxElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		RelaxElapsedTime += DeltaSeconds;
		bShouldEnterRelaxState = (RelaxElapsedTime >= EnterRelaxThreshold);
	}
}
