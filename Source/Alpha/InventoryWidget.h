// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WidgetBase.h"
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


protected:
	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	void PopulateGridPanel(UUniformGridPanel* const grid,
						   const TSubclassOf<UWidgetBase> slot_t) const;
	
/*	// Why would anybody need to get an InventoryCompnent?
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryComponent* GetInventoryComponent();
	*/
	
private:
	bool init_inventory();

	UPROPERTY()
	UInventoryComponent* _inventory;
};
