// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Item.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Category")
	virtual bool Add(AItem* item);

	UFUNCTION(BlueprintCallable, Category = "Category")
	virtual void Remove(AItem* item);

	UFUNCTION(BlueprintCallable, Category = "Category")
	virtual bool CanFit(AItem* item);

	UFUNCTION(BlueprintCallable, Category = "Category")
	virtual bool Contains(AItem* item);

protected:
	
private:
	/* checks if item can fit in inventory, and gives x,y coordinates,
		x,y are untouched if CanFIt returns false */
	bool CanFit(AItem* item, uint8& x, uint8& y);

	bool Contains(AItem* item, uint8& x, uint8& y);


	/* Mini matrix class */
	AItem* get_item(const uint8 x, const uint8 y);
	void set_item(const uint8 x, const uint8 y, AItem* item_ptr);

	uint8 _gridheight;
	uint8 _gridwidth;	

	UPROPERTY()
	TArray<AItem*> _grid;
	
};
