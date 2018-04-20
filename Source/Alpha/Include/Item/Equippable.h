// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "Equippable.generated.h"

/**
 * An Equppable item
 * Implements Interactable intefrace, when interacted with the item is equpped,
 * if the item is already equipped the item is then unequipped.
 * Functions here are (mostly) used by ActiveInventoryComponent
 */
UCLASS()
class ALPHA_API AEquippable : public AItem
{
	GENERATED_BODY()
	
public:
	
	AEquippable();

	/* Callback, called when this item is equipped. */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual bool Equip(AActor* actor);

	/* Callback, called when this item is unequipped. */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual bool UnEquip();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual bool CanEquip(AActor* actor) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual bool IsEquipped() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual AActor* GetItemOwner() const;

private:
	AActor* _owner;
};
