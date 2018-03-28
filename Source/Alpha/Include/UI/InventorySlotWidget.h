// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Include/UI/WidgetBase.h"
#include "Include/Item/Item.h"
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
	
	void SetParent(class UInventoryWidget* w);

	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	void SetItem(AItem* const item);

	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	AItem* GetItem();


	/* Called from OnDrop even in blueprint */
	UFUNCTION(BlueprintCallable, Category="Drag and Drop")
	bool HandleOnDrop(
		FGeometry MyGeometry,
		FPointerEvent PointerEvent,
		UDragDropOperation* Operation
	); 

protected:
	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	UTexture2D* GetIcon() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InventoryUI")
	UTexture2D* DefaultIcon;

private:
	UPROPERTY()
	class UInventoryWidget* _parent;

	UPROPERTY()
	AItem* _item;
	
};