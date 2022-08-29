// Fill out your copyright notice in the Description page of Project Settings.


#include "RedBarrel.h"
#include "Components\StaticMeshComponent.h"
#include "PhysicsEngine\RadialForceComponent.h"
// Sets default values
ARedBarrel::ARedBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = StaticMesh;

	RadialForce = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForce->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawneds
void ARedBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARedBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

