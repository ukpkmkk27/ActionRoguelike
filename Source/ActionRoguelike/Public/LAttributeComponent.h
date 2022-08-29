// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, InstigatorActor, ULAttributeComponent*, OwningComp, float, NewHealth, float, Delta);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROGUELIKE_API ULAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULAttributeComponent();

protected:

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Attributes")
	float Health;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	float HealthMax = 100.0f;

public:	

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool ApplyHealthChange(AActor* InstigateActor,float Delta);
	UFUNCTION(BlueprintCallable)
	bool IsAlive() const;
	UFUNCTION(BlueprintCallable)
	static ULAttributeComponent* GetAttributeComp(AActor* From);
	UFUNCTION(BlueprintCallable)
	static bool IsAliveActor(AActor* From);
	float GetHealth();
};
