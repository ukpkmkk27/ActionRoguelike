// Fill out your copyright notice in the Description page of Project Settings.


#include "LBlackHole.h"
#include "Engine\Classes\PhysicsEngine\RadialForceComponent.h"

ALBlackHole::ALBlackHole()
{
	PullForcecomp = CreateDefaultSubobject<URadialForceComponent>("PullForceComp");
	PullForcecomp->SetupAttachment(RootComponent);

}

void ALBlackHole::BeginPlay()
{
	Super::BeginPlay();

}
void ALBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}