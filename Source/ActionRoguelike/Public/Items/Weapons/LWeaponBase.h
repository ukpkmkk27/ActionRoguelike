// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LWeaponBase.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class ACTIONROGUELIKE_API ALWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALWeaponBase();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WeaponMeshComponent")
	UStaticMeshComponent* WeaponMeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "WeaponCollisionBox")
	UBoxComponent* WeaponCollisionBox;
public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() { return WeaponCollisionBox;}
};
