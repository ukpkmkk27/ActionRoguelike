// Yujiang Li All Rights Reserved


#include "DataAssets/Input/LDataAsset_InputConfig.h"
#include "LDebugHelper.h"
UInputAction* ULDataAsset_InputConfig::FindNativeActionByTag(const FGameplayTag& InGameplayTag) const
{
	
	for (const FLInputConfig& InputConfig : NativeInputActions)
	{
		if (InputConfig.GameplayTag == InGameplayTag && InputConfig.InputAction)
		{
			return InputConfig.InputAction;
		}
	}

	return nullptr;
}
