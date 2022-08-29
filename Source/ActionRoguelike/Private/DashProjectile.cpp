// Fill out your copyright notice in the Description page of Project Settings.


#include "DashProjectile.h"
#include "Particles\ParticleSystemComponent.h"
#include "GameFramework\ProjectileMovementComponent.h"
#include "kismet/GameplayStatics.h"

ADashProjectile::ADashProjectile()
{
	MovementComp->InitialSpeed = 8000.0f;
	TeleportDelay = 0.2f;
	DetonateDelay = 0.2f;

}
void ADashProjectile::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle_DelayDetonate,this,&ADashProjectile::Explode,DetonateDelay);

}
void ADashProjectile::Explode_Implementation()
{
	GetWorldTimerManager().ClearTimer(TimerHandle_DelayDetonate);

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactVFX, GetActorLocation(), GetActorRotation());

	//call VFX and stop Particlecomponenet
	EffectComp->DeactivateSystem();
	//stop movement
	MovementComp->StopMovementImmediately();
	//prevent overlap or others event product
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_DelayTeleport;
	GetWorldTimerManager().SetTimer(TimerHandle_DelayTeleport, this, &ADashProjectile::TeleportInstigator, TeleportDelay);

}
void ADashProjectile::TeleportInstigator()
{
	AActor* ActorToTeleport = GetInstigator();
	if (ensureAlways(ActorToTeleport))
	{
		ActorToTeleport->TeleportTo(GetActorLocation(),ActorToTeleport->GetActorRotation());
	}
}
