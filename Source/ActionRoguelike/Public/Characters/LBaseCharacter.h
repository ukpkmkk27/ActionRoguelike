// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interfaces/LPawnCombatInterface.h"
#include "LBaseCharacter.generated.h"


class ULAbilitySystemComponent;
class ULAttributeSet;
class ULDataAsset_StartUpDataBase;
class UILPawnCombatInterface;
class UPawnCombatComponent;

UCLASS()
class ACTIONROGUELIKE_API ALBaseCharacter : public ACharacter, public IAbilitySystemInterface, public ILPawnCombatInterface
{
	GENERATED_BODY()

public:
	
	ALBaseCharacter();
	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface

	//~ Begin ILPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End ILPawnCombatInterface Interface

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULAbilitySystemComponent* LAbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULAttributeSet* LAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<ULDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE ULAbilitySystemComponent* GetLAbilitySystemComponent() const { return LAbilitySystemComponent; }
	FORCEINLINE ULAttributeSet* GetLAttributeSet() const { return LAttributeSet; }
	

};
