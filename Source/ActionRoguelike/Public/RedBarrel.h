// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RedBarrel.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;
UCLASS()
class ACTIONROGUELIKE_API ARedBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARedBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite);
	URadialForceComponent* RadialForce;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
