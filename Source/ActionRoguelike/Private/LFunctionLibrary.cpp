// Yujiang Li All Rights Reserved


#include "LFunctionLibrary.h"
#include "AbilitySystem/LAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Interfaces/LPawnCombatInterface.h"

ULAbilitySystemComponent* ULFunctionLibrary::NativeGetLASCFromActor(AActor* InActor)
{
	check(InActor);
	return Cast<ULAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));


}

void ULFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	ULAbilitySystemComponent* ASC = NativeGetLASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void ULFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	ULAbilitySystemComponent* ASC = NativeGetLASCFromActor(InActor);
	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool ULFunctionLibrary::NativeDoesActorHasTag(AActor* InActor, FGameplayTag TagToCheck)
{
	ULAbilitySystemComponent* ASC = NativeGetLASCFromActor(InActor);
	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void ULFunctionLibrary::BP_DoesActorHasTag(AActor* InActor, FGameplayTag TagToCheck, LConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHasTag(InActor, TagToCheck) ? LConfirmType::Yes : LConfirmType::No;
}

UPawnCombatComponent* ULFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);

	if (ILPawnCombatInterface* PawnCombatInterface = Cast<ILPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}

	return nullptr;
}

UPawnCombatComponent* ULFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, LValidType& OutValidType)
{
	UPawnCombatComponent* PawnCombatComponent = NativeGetPawnCombatComponentFromActor(InActor);
	PawnCombatComponent ? LValidType::Valid : LValidType::Invalid;

	return PawnCombatComponent;
}
