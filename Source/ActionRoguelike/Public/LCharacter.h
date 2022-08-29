// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LCharacter.generated.h"



class USpringArmComponent;
class UCameraComponent;
class ULInteractionComponent;
class UAnimMontage;
class ULAttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API ALCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> BlackHole;

	UPROPERTY(EditAnywhere,Category = "Attack")
	TSubclassOf<AActor> MagicProjectile;
	
	UPROPERTY(EditAnyWhere, Category = "Attack")
	TSubclassOf<AActor> DashProjectile;

	FTimerHandle TimerHandle_PrimaryAttack;
	
public:

	// Sets default values for this character's properties
	ALCharacter();
protected:
	//Camera and SpringArm
	UPROPERTY(VisibleAnywhere);
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere);
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	ULInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Components")
	ULAttributeComponent* AttributeComp;


	//Called when Character MoveForward and MoveRight
	void MoveForward(float value);
	void MoveRight(float value);

	//Spawn
	void Spawn(TSubclassOf<AActor> ProjectileClass);

	//Primary Attack
	void PrimaryAttack();
	void PrimaryAttack_TimeElapsed();

	//Black Hloe Attack
	void BlackHoleAttack();
	void BlackHoleAttack_TimeElapsed();

	//DashProjectile Attack
	void DashProjectileAttack();
	void DashProjectileAttack_TimeElapsed();

	//Primary Interact
	void PrimaryInteract();
	
	virtual void PostInitializeComponents();
public:	

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, ULAttributeComponent* OwningComp, float NewHealth, float Delta);
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

};
