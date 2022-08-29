// Fill out your copyright notice in the Description page of Project Settings.


#include "LMagicProjectile.h"
#include "LAttributeComponent.h"
#include "Components\SphereComponent.h"
#include "Engine\Classes\Components\AudioComponent.h"
#include "Engine\Classes\Sound\SoundCue.h"
#include "Engine\Classes\Kismet\GameplayStatics.h"
ALMagicProjectile::ALMagicProjectile()
{
	DamageAmount = -20.0f;

	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ALMagicProjectile::OnActorOverLap);

	HitSound = LoadObject<USoundCue>(this,TEXT("SoundCue'/Game/ActionRoguelike/Audio/MagicProjectile_Impact.MagicProjectile_Impact'"));
													
	AudioComp = CreateDefaultSubobject<UAudioComponent>("AudioComp");
	AudioComp->SetupAttachment(RootComponent);

}

void ALMagicProjectile::OnActorOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{ 
	
	if (OtherActor&&OtherActor!=GetInstigator())
	{
		ULAttributeComponent* AttributeComp =Cast<ULAttributeComponent>(OtherActor->GetComponentByClass(ULAttributeComponent::StaticClass()));
		if (HitSound)
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(),HitSound,SweepResult.Location);
		}
		if (AttributeComp)
		{
			AttributeComp->ApplyHealthChange(GetInstigator(),DamageAmount);
			Destroy();
			
		}
	}
}

