// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WidgetBase.h"
#include "InventoryComponent.h"
#include "CharacterBase.h"
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

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	uint8 GetXSize() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	uint8 GetYSize() const;
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryComponent* GetInventoryComponent();
	
private:
	UPROPERTY()
	UInventoryComponent* _inventory;
};
