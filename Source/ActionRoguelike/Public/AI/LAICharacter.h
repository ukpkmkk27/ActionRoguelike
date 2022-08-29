// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LAICharacter.generated.h"
class ULAttributeComponent;
class UPawnSensingComponent;
class UUserWidget;
class ULWorldUserWidget;
UCLASS()
class ACTIONROGUELIKE_API ALAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALAICharacter();

protected:
	ULWorldUserWidget* ActiveHealthBar;
	UPROPERTY(VisibleAnywhere,Category="Effect")
	FName MaterialName;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPawnSensingComponent* PawnSensingComp;
	UPROPERTY(VisibleAnyWhere, Category = "Attributes")
	ULAttributeComponent* AttributeComp;
	UPROPERTY(EditDefaultsOnly,Category="Effect")
	TSubclassOf<UUserWidget> HealthBarWidgetClass;


	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnPawnSeen(APawn* Pawn);
	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, ULAttributeComponent* OwningComp, float NewHealth, float Delta);
	void SetTargetActor(AActor* InstigatorActor);

};
 