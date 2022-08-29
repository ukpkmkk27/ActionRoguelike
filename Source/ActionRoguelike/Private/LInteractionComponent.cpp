// Fill out your copyright notice in the Description page of Project Settings.


#include "LInteractionComponent.h"
#include "LGameplayInterface.h"
#include "DrawDebugHelpers.h"
// Sets default values for this component's properties
ULInteractionComponent::ULInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void ULInteractionComponent::PrimaryInteract()
{

	FCollisionObjectQueryParams objectQueryParams;
	objectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	AActor* myOwner = GetOwner();

	FVector eyeLocation;
	FRotator eyeRotation;
	myOwner->GetActorEyesViewPoint(eyeLocation, eyeRotation);
	FVector end = eyeLocation + (eyeRotation.Vector() * 1000);

	//FHitResult hit;
	//bool bBlockingHit = GetWorld()->LineTraceSingleByObjectType(hit,eyeLocation,end,objectQueryParams);
	
	TArray<FHitResult> Hits;

	float Radius = 30.0f;

	FCollisionShape Shape;
	Shape.SetSphere(Radius);

	bool bBlockingHit = GetWorld()->SweepMultiByObjectType(Hits, eyeLocation, end, FQuat::Identity, objectQueryParams, Shape);

	FColor LineColor = bBlockingHit ? FColor::Green : FColor::Red;

	for (FHitResult hit : Hits)
	{
		AActor* hitActor = hit.GetActor();
		if (hitActor)
		{
			if (hitActor->Implements<ULGameplayInterface>())
			{
				APawn* myPawm = Cast<APawn>(myOwner);

				ILGameplayInterface::Execute_InterAct(hitActor, myPawm);

				break;
			}
		}

		DrawDebugSphere(GetWorld(),hit.ImpactPoint, Radius, 32, LineColor, false,3.0f);
	}
	 
	
	DrawDebugLine(GetWorld(), eyeLocation, end, LineColor, false, 2.0f, 0, 2.0f);
}