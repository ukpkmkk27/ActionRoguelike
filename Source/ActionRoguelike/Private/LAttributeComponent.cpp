// Fill out your copyright notice in the Description page of Project Settings.


#include "LAttributeComponent.h"

// Sets default values for this component's properties
ULAttributeComponent::ULAttributeComponent()
{
	Health = HealthMax;
		
}

//只能通过这个改变生命值
bool ULAttributeComponent::ApplyHealthChange(AActor* InstigateActor,float Delta)
{
	Health += Delta;
	if (Health < 0 || Health>100)
	{
		Health = Health > 100 ? 100 : 0;
	}

	OnHealthChanged.Broadcast(InstigateActor, this, Health, Delta);
	return true;
}

bool ULAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool ULAttributeComponent::IsAliveActor(AActor* From)
{
	if (From)
	{
		return ULAttributeComponent::GetAttributeComp(From)->IsAlive();
	}
	return false;
}

float ULAttributeComponent::GetHealth()
{
	return Health;
}

ULAttributeComponent* ULAttributeComponent::GetAttributeComp(AActor* From)
{
	if (From)
	{
		return Cast<ULAttributeComponent>(From->GetComponentByClass(ULAttributeComponent::StaticClass()));
	}
	return nullptr;
}

