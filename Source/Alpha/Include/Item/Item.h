// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Include/Character/VisualActor.h"
#include "Interactable.h"
#include "Item.generated.h"

/*
 * An Item, the base class for all items in the game.
 * Implemets Interactable intefrace, this is used to pick items up.
 */

UCLASS()
class ALPHA_API AItem : public AVisualActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	AItem();

	/* Prompts an interact, returns true if interaction was sucessful. */
	bool Interact() override;

	bool CanInteract() override;

	FString GetInteractableName() override;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	uint8 GetXSize();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	uint8 GetYSize();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UTexture2D* GetIcon() const;

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	uint8 _xsize;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	uint8 _ysize;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	UTexture2D* _icon;
};
