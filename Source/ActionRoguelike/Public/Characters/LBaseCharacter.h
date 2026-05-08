// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "LBaseCharacter.generated.h"


class ULAbilitySystemComponent;
class ULAttributeSet;

UCLASS()
class ACTIONROGUELIKE_API ALBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	ALBaseCharacter();
	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystemInterface Interface


protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULAbilitySystemComponent* LAbilitySystemComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ULAttributeSet* LAttributeSet;
public:
	FORCEINLINE ULAbilitySystemComponent* GetLAbilitySystemComponent() const { return LAbilitySystemComponent; }
	FORCEINLINE ULAttributeSet* GetLAttributeSet() const { return LAttributeSet; }
	

};
