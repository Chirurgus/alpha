// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "Item.h"
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
	void SetItem(const AItem* const item);

protected:
	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	UTexture2D* GetIcon() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryUI")
	UTexture2D* DefaultIcon;

private:
	UPROPERTY()
	const AItem* _item;
	
};