// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "Equippable.generated.h"

/**
 * An Equppable item
 * Implements Interactable intefrace, when interacted with the item is equpped,
 * if the item is already equipped the item is then unequipped.
 */
UCLASS()
class ALPHA_API AEquippable : public AItem
{
	GENERATED_BODY()
	
public:
	
	AEquippable();

	/* Callback, called when this item is equipped. */
	UFUNCTION()
	virtual bool Equip(AActor* actor);

	/* Callback, called when this item is unequipped. */
	UFUNCTION()
	virtual bool UnEquip();

	UFUNCTION()
	virtual bool CanEquip(AActor* actor);

private:
	AActor* _owner;
};
