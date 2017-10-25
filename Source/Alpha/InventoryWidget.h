// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WidgetBase.h"
#include "InventorySlotWidget.h"
#include "CharacterBase.h"
#include "UniformGridPanel.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API UInventoryWidget : public UWidgetBase
{
	GENERATED_BODY()
	
public:
	UInventoryWidget(const FObjectInitializer& obj_init);
	
	bool Initialize() override;

	/* Called from OnDrop even in blueprint */
	UFUNCTION(BlueprintCallable, Category="Drag and Drop")
	bool MoveItem(AItem* item, uint8 column, uint8 row); 

protected:
	/* Clears the grid, and adds needed number of slot_t's
	   and positions them in the needed row/column.
	*/
	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	void ResizeGridPanel(UUniformGridPanel* const grid,
						   const TSubclassOf<UInventorySlotWidget> slot_t);
	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	void PopulateGridPanel(UUniformGridPanel* const grid,
						   const TSubclassOf<UInventorySlotWidget> slot_t);

	
private:
	UInventorySlotWidget* get_slot(const uint8 x,
					  const uint8 y,
					  UUniformGridPanel* const grid) const;

	bool init_inventory();

	UPROPERTY()
	UInventoryComponent* _inventory;
};
