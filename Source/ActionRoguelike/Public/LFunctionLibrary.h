// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "LTypes/LEnumTypes.h"
#include "LFunctionLibrary.generated.h"



/**
 * 
 */
class UPawnCombatComponent;
class ULAbilitySystemComponent;
UCLASS()
class ACTIONROGUELIKE_API ULFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static ULAbilitySystemComponent* NativeGetLASCFromActor(AActor* InActor);
	
	UFUNCTION(BlueprintCallable, Category = "L|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "L|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);
	
	static bool NativeDoesActorHasTag(AActor* InActor, FGameplayTag TagToCheck); //cpp version

	UFUNCTION(BlueprintCallable, Category = "L|FunctionLibrary",meta = (DisplayName = "Does Actor Has Tag",ExpandEnumAsExecs="OutConfirmType"))
	static void BP_DoesActorHasTag(AActor* InActor, FGameplayTag TagToCheck, LConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor); //cpp version

	UFUNCTION(BlueprintCallable, Category = "L|FunctionLibrary", meta = (DisplayName = "Get PawnCombatComponent From Actor", ExpandEnumAsExecs ="OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, LValidType& OutValidType);
};
