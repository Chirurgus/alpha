// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "Item.h"
#include "InventoryDragDropOperation.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API UInventoryDragDropOperation : public UDragDropOperation
{
	GENERATED_BODY()
	
public:
	UInventoryDragDropOperation();
	
	UFUNCTION(BlueprintCallable, Category = "Drag and Drop")
	void SetItem(AItem* item);
	
	UFUNCTION(BlueprintCallable, Category = "Drag and Drop")
	AItem* GetItem() const;

	
private:
	UPROPERTY()
	AItem* _item;
};
