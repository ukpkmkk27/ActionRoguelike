// Fill out your copyright notice in the Description page of Project Settings.


#include "LItemChest.h"
#include "Components\StaticMeshComponent.h"

// Sets default values
ALItemChest::ALItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TargetPitch = 110;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	RootComponent = BaseMesh;
	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);
	
}

void ALItemChest::InterAct_Implementation(APawn* InstigatorPawn)
{ 

	//LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));

}


