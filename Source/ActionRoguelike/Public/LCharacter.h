// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LCharacter.generated.h"



class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ACTIONROGUELIKE_API ALCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALCharacter();

protected:
	//Camera and SpringArm
	UPROPERTY(VisibleAnywhere);
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere);
	UCameraComponent* CameraComp;

	//Called when Character MoveForward
	void MoveForward(float value);



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
