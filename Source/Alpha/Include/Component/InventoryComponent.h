// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"

#include "Include/Item/Item.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	/* UInventoryWidget (and only it) need to acess the raw inventory matrix */
	friend class UInventoryWidget;

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	uint8 GetXSize() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	uint8 GetYSize() const;
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual bool Add(AItem* item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual void Remove(AItem* item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual bool CanFit(AItem* item) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	virtual bool Contains(AItem* item) const;

	UFUNCTION()
	bool MoveItem(AItem* item, const uint8 target_col, const uint8 target_row);

	/* Checks if item can be moved to i,j, even by swaping if necesseary */
	UFUNCTION()
	bool CanMove(AItem* item, const uint8 target_col, const uint8 target_row) const;

protected:
	
private:

	/* Higher level set_item function */
	void SetItem(AItem* item, uint8 row, uint8 column);	

	/* checks if item can fit in inventory, and gives x,y coordinates,
		x,y are untouched if CanFIt returns false */
	bool CanFit(AItem* item, uint8& column, uint8& row) const;

	bool Contains(AItem* item, uint8& column, uint8& row) const;


	/* Mini matrix class */
	/* in-class defined to allow inline function to be called
		from another translation unit
	*/
	/* To have a single place where the coefs are calculated */
	uint8 get_item_pos(const uint8 row, const uint8 column) const {
		return _gridwidth * row + column;
	}
	AItem* get_item(const uint8 row, const uint8 column) const {
		return _grid[get_item_pos(row, column)];
	}
	void set_item(const uint8 row, const uint8 column, AItem* item_ptr) {
		_grid[get_item_pos(row, column)] = item_ptr;
	}

	uint8 _gridheight;
	uint8 _gridwidth;	

	UPROPERTY()
	TArray<AItem*> _grid;
	
};
