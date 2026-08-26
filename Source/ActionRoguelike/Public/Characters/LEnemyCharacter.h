// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Characters/LBaseCharacter.h"
#include "LEnemyCharacter.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ALEnemyCharacter : public ALBaseCharacter
{
	GENERATED_BODY()

public:
	ALEnemyCharacter();

	//~ Begin ILPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End ILPawnCombatInterface Interface

	FORCEINLINE UEnemyCombatComponent* GetEnemyConbatComponent() const { return EnemyCombatComponent; }

protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

};
