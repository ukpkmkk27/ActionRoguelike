// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LTargetDummy.generated.h"

class ULAttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API ALTargetDummy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALTargetDummy();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Comp")
		ULAttributeComponent* AttributeComp;
	UPROPERTY(VisibleAnywhere, Category = "Comp")
		UStaticMeshComponent* StaticMesh;
	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, ULAttributeComponent* OwningComp, float NewHealth, float Delta);
public:


};
