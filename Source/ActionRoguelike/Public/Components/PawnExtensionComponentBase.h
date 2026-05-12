// Yujiang Li All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROGUELIKE_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()


protected:
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T'Template parameter to GetPawn must be derived from a APawn");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return CastChecked<APawn>(GetOwner());
	}

	template <class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T'Template parameter to GetController must be derived from a AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}

		
};
