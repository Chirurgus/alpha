// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "InventorySlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API UInventorySlotWidget : public UWidgetBase
{
	GENERATED_BODY()

public:
	UInventorySlotWidget(const FObjectInitializer& obj_init);
	
	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	void SetIcon(UTexture2D* const icon);

protected:
	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	UTexture2D* const GetIcon() const;

private:
	UPROPERTY()
	UTexture2D* _icon;
};
