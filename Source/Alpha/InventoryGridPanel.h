// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBase.h"
#include "Components/UniformGridPanel.h"
#include "InventoryComponent.h"
#include "InventoryGridPanel.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API UInventoryGridPanel : public UUniformGridPanel
{
	GENERATED_BODY()
	
public:

	UInventoryGridPanel(const FObjectInitializer& obj_init);

	void OnCreationFromPalette() override;

	UFUNCTION(BlueprintCallable, Category = "InventoryUI")
	void Resize();

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "InventoryUI")
	TSubclassOf<UWidgetBase> GridSlotType;
	
private:
	UPROPERTY()
	UInventoryComponent* _inventory;
};
