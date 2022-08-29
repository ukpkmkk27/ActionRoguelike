// Fill out your copyright notice in the Description page of Project Settings.


#include "LTargetDummy.h"
#include "LAttributeComponent.h"
#include "Components\StaticMeshComponent.h"
// Sets default values
ALTargetDummy::ALTargetDummy()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = StaticMesh;

	AttributeComp = CreateDefaultSubobject<ULAttributeComponent>("AttributeComp");
	AttributeComp->OnHealthChanged.AddDynamic(this, &ALTargetDummy::OnHealthChanged);


}
void ALTargetDummy::OnHealthChanged(AActor* InstigatorActor, ULAttributeComponent* OwningComp, float NewHealth, float Delta)
{
	if (Delta < 0.0f)
	{
		StaticMesh->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->GetTimeSeconds());

	}
}




