// Yujiang Li All Rights Reserved


#include "DataAssets/StartUp/LDataAsset_HeroStartUpData.h"
#include "AbilitySystem/Abilities/LHeroGameplayAbility.h"
#include "AbilitySystem/LAbilitySystemComponent.h"


void ULDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(ULAbilitySystemComponent* InASCToGive, int32 ApplyInLevel)
{
    Super::GiveToAbilitySystemComponent(InASCToGive, ApplyInLevel);
    for (const FLHeroAbilityConfig& HeroAbilityConfig : HeroStartUpAbilitySet)
    {
        if (!HeroAbilityConfig.IsValid()) continue;
        FGameplayAbilitySpec GameplayAbilitySpec(HeroAbilityConfig.AbilityToGrant);
        GameplayAbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
        GameplayAbilitySpec.Level = ApplyInLevel;
        GameplayAbilitySpec.DynamicAbilityTags.AddTag(HeroAbilityConfig.InputTag); //By doing this, we can retrive ability by tag. 

        InASCToGive->GiveAbility(GameplayAbilitySpec);

    }
}
