// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LWorldUserWidget.generated.h"

/**
 * 
 */
class USizeBox;
UCLASS()
class ACTIONROGUELIKE_API ULWorldUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(meta = (BindWidget))
	USizeBox* ParentSizeBox;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "UI")
	FVector WorldOffset;
public:

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	AActor* AttachedActor;
	
};
