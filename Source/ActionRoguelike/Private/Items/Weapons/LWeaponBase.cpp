// Yujiang Li All Rights Reserved


#include "Items/Weapons/LWeaponBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "LDebugHelper.h"
// Sets default values
ALWeaponBase::ALWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	WeaponMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMeshComponent"));
	SetRootComponent(WeaponMeshComponent);
	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetBoxExtent(FVector(20.f));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnCollisionBoxBeginOverlap);
	WeaponCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnCollisionBoxEndOverlap);
}

void ALWeaponBase::OnCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* WeaponOwingPawn = GetInstigator<APawn>();
	checkf(WeaponOwingPawn, TEXT("Forgot to assign an instigator as the owining pawn of the weapon:%s"), *GetName());
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (HitPawn != WeaponOwingPawn)
		{
			Debug::Print(GetName() + TEXT("begin overlap with ") + HitPawn->GetName(),FColor::Green);
		}

		//TODO::Implement the check of Enemy Characters
	}
}

void ALWeaponBase::OnCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndext)
{

	APawn* WeaponOwingPawn = GetInstigator<APawn>();
	checkf(WeaponOwingPawn, TEXT("Forgot to assign an instigator as the owining pawn of the weapon:%s"), *GetName());
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (HitPawn != WeaponOwingPawn)
		{
			Debug::Print(GetName() + TEXT("end overlap with ") + HitPawn->GetName(),FColor::Red);
		}

		//TODO::Implement the check of Enemy Characters
	}

}
