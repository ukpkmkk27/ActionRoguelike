// Yujiang Li All Rights Reserved


#include "AnimInstances/Hero/LHeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/LHeroAnimInstance.h"

ULHeroAnimInstance* ULHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<ULHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}