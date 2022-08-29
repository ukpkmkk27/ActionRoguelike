// Fill out your copyright notice in the Description page of Project Settings.


#include "LCharacter.h"
#include "GameFramework\SpringArmComponent.h"
#include "Camera\CameraComponent.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "LInteractionComponent.h"
#include "Engine\Classes\Kismet\KismetMathLibrary.h"
#include "LAttributeComponent.h"

// Sets default values
ALCharacter::ALCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	AttributeComp = CreateDefaultSubobject<ULAttributeComponent>("AttributeComp");
	InteractionComp = CreateDefaultSubobject<ULInteractionComponent>("InteractionComp");
	
}

void ALCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AttributeComp->OnHealthChanged.AddDynamic(this, &ALCharacter::OnHealthChanged);
}


// Called to bind functionality to input
void ALCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ALCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &ALCharacter::PrimaryInteract);
	
	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&ALCharacter::Jump);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ALCharacter::PrimaryAttack);
	
	PlayerInputComponent->BindAction("BlackHoleAttack", IE_Pressed, this, &ALCharacter::BlackHoleAttack);

	PlayerInputComponent->BindAction("DashProjectileAttack", IE_Pressed, this, &ALCharacter::DashProjectileAttack);
	
}


void ALCharacter::MoveForward(float value)
{
	FRotator controlRot = GetControlRotation();
	controlRot.Pitch = 0.0f;
	controlRot.Roll = 0.0f;
	AddMovementInput(controlRot.Vector(), value);
}

void ALCharacter::MoveRight(float value)
{
	FRotator controlRot = GetControlRotation();
	controlRot.Pitch = 0.0f;
	controlRot.Roll = 0.0f;
	// x == forward
	// y == right
	// z == up
	FVector rightVector = FRotationMatrix(controlRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(rightVector, value);
}

void ALCharacter::PrimaryAttack()
{
	PlayAnimMontage(AttackAnim);
	GetWorldTimerManager().SetTimer(TimerHandle_PrimaryAttack, this, &ALCharacter::PrimaryAttack_TimeElapsed, 0.23f);
	//If Character died,Clear the Timer;
	//GetWorldTimerManager().ClearTimer(TimerHandle_PrimaryAttack);

	
}
void ALCharacter::PrimaryAttack_TimeElapsed()
{
	Spawn(MagicProjectile);
	
}


void ALCharacter::BlackHoleAttack()
{
	PlayAnimMontage(AttackAnim);
	GetWorldTimerManager().SetTimer(TimerHandle_PrimaryAttack, this, &ALCharacter::BlackHoleAttack_TimeElapsed, 0.23f);
}
void ALCharacter::BlackHoleAttack_TimeElapsed()
{
	Spawn(BlackHole);
}


void ALCharacter::DashProjectileAttack()
{
	PlayAnimMontage(AttackAnim);
	GetWorldTimerManager().SetTimer(TimerHandle_PrimaryAttack, this, &ALCharacter::DashProjectileAttack_TimeElapsed, 0.23f);
}
void ALCharacter::DashProjectileAttack_TimeElapsed()
{
	Spawn(DashProjectile);

}
void ALCharacter::Spawn(TSubclassOf<AActor> ClassToSpawn)
{
	if (ensureAlways(ClassToSpawn))
	{
		FHitResult hitResult;

		FCollisionShape shape;
		shape.SetSphere(20.f);

		FCollisionQueryParams params;
		params.AddIgnoredActor(this);

		FCollisionObjectQueryParams objParams;
		objParams.AddObjectTypesToQuery(ECC_WorldStatic);
		objParams.AddObjectTypesToQuery(ECC_WorldDynamic);
		objParams.AddObjectTypesToQuery(ECC_Pawn);

		FVector traceStart = CameraComp->GetComponentLocation();
		FVector traceEnd = traceStart + (GetControlRotation().Vector() * 5000.0f);

		if (GetWorld()->SweepSingleByObjectType(hitResult, traceStart, traceEnd, FQuat::Identity, objParams, shape, params))
		{
			traceEnd = hitResult.ImpactPoint;
		}

		//SpawnLocation
		FVector HandLocation = GetMesh()->GetSocketLocation("Muzzle_01");

		//SpawnRotation
		FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(HandLocation, traceEnd);

		FTransform SpawnTM = FTransform(TargetRotation, HandLocation);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.Instigator = this;
		GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnTM, SpawnParams);
	}
	
}

void ALCharacter::PrimaryInteract()
{
	if(InteractionComp)
	{
		InteractionComp->PrimaryInteract();
	}
	
}

void ALCharacter::OnHealthChanged(AActor* InstigatorActor, ULAttributeComponent* OwningComp, float NewHealth, float Delta)
{
	if (Delta < 0.0f)
	{
		
		GetMesh()->SetScalarParameterValueOnMaterials("TimeHit", GetWorld()->TimeSeconds);

	}

	if (NewHealth <= 0.0f && Delta < 0.0f)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		DisableInput(PC);
	}
}
