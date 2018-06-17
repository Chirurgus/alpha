// Fill out your copyright notice in the Description page of Project Settings.
#include "Include/Alpha.h"

#include "Include/Component/InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
	: _grid {}
	, _gridheight {3}
	, _gridwidth {3}
{
	//This component will be manually updated and paged
	PrimaryComponentTick.bCanEverTick = false;

	for (uint8 i {0}; i < (_gridheight * _gridwidth); ++i) {
		_grid.Add(nullptr);
	}
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	/*
		PRINT_DEBUG_MESSAGE("=============================");
	for (uint8 i {_gridheight}; i-- > 0;) {
		FString s {};
		for (uint8 j {0}; j < _gridwidth; ++j) {
			s += (get_item(i,j) ? "1 " : "0 ");
		}
		PRINT_DEBUG_MESSAGE(s);
	}
	*/


	// ...
	
}

uint8 UInventoryComponent::GetXSize() const
{
	return _gridwidth;
}

uint8 UInventoryComponent::GetYSize() const
{
	return _gridheight;
}


bool UInventoryComponent::Add(AItem * item)
{
	if (Contains(item)) {
		return false;
	}
	uint8 x;
	uint8 y;
	if (!CanFit(item,x,y)) {
		return false;
	}

	for (uint8 i {0}; i < item->GetYSize(); ++i) {
		for (uint8 j {0}; j < item->GetXSize(); ++j) {
			set_item(y + i,x + j,item);
		}
	}

	/*
	PRINT_DEBUG_MESSAGE("=============================");
	for (uint8 i {0}; i < _gridheight; ++i) {
		FString s {};
		for (uint8 j {0}; j < _gridwidth; ++j) {
			s += (get_item(i,j) ? "1 " : "0 ");
		}
		PRINT_DEBUG_MESSAGE(s);
	}
	*/

	PRINT_DEBUG_MESSAGE("Picked up: " + item->GetInteractableName());
	return true;
}

void UInventoryComponent::Remove(AItem * item)
{
	uint8 x;
	uint8 y;
	if (!Contains(item, x, y)) {
		return;
	}
	for (uint8 i {0}; i < item->GetYSize(); ++i) {
		for (uint8 j {0}; j < item->GetXSize(); ++j) {
			set_item(y + i, x + j, nullptr); 
		}
	}
	
}

bool UInventoryComponent::CanFit(AItem * item) const
{	
	uint8 x,y;
	return CanFit(item, x, y);
}

bool UInventoryComponent::Contains(AItem * item) const
{
	if (!item) {
		return false;
	}
	for (uint8 i {0}; i < _gridheight; ++i) {
		for (uint8 j {0}; j < _gridwidth; ++j) {
			if (get_item(i,j) == item) {
				return true;
			}
		}
	}
	return false;
}

bool UInventoryComponent::MoveItem(AItem * item, const uint8 target_col, const uint8 target_row)
{
	/* Don't allow swapping. */
	if (CanMove(item,target_col,target_row)) {
		Remove(item);
		/*
		if (AItem* target_item {get_item(target_row, target_col)}) {
			uint8 item_col, item_row;
			if (!Contains(item, item_row, item_col)) {
				UE_LOG(ALog, Error, TEXT("FUCK FUCK FUCK FUKC FUKC"));
			}
			Remove(target_item);
			SetItem(target_item, item_row, item_col);
			UE_LOG(ALog, Log, TEXT("item_row = %i item_col = %i"), item_row, item_col);
		}
		*/
		SetItem(item, target_row, target_col);
		UE_LOG(ALog, Log, TEXT("target_row = %i target_col = %i"), target_row, target_col);
		return true;
	}
	return false;
}

bool UInventoryComponent::CanMove(AItem * item, const uint8 target_col, const uint8 target_row) const
{
	uint8 item_row {}, item_col {};

	if (!item ||
		target_col >= _gridwidth ||
		target_row >= _gridheight ||
		!Contains(item, item_col, item_row))
	{
		return false;
	}
	TArray<AItem*> tmp_array(_grid);
	for (auto& p : tmp_array) {
		if (p == item) {
			p = nullptr;
		}
	}
	
	/* prevent swapping , just return false */

	/* if there is an item in the target slot => try to swap
		- unequip the item
		- see if it can fit in item's original place
		*/
//	if (AItem* target_item {tmp_array[get_item_pos(target_row,target_col)]}) {

		/* unequip the item */
		/*
		for (auto& p : tmp_array) {
			if (p == target_item) {
				p = nullptr;
			}
		}
		*/
		/* check if item overlaps any other items */
		/*
		for (uint8 i {0}; i < item->GetYSize(); ++i) {
			for (uint8 j {0}; j < item->GetXSize(); ++j) {
				if ((i + target_row) >= _gridheight || (j + target_col) >= _gridwidth || tmp_array[get_item_pos(target_row+i,target_col+j)]) {
					PRINT_DEBUG_MESSAGE("item overlaps many items");
					return false;
				}
			}
		}
		*/

		/* see if target_item fits into item's original slot */
		/*
		for (uint8 i {0}; i < target_item->GetYSize(); ++i) {
			for (uint8 j {0}; j < target_item->GetXSize(); ++j) {
				if ((i + target_row) >= _gridheight || (j + target_col) >= _gridwidth || tmp_array[get_item_pos(target_row+i,target_col+j)]) {
					PRINT_DEBUG_MESSAGE("Target_item doesn't fit into item's slot");
					return false;
				}
			}
		}
		*/
//	}

	/* Check if item fits in target */
	for (uint8 i {0}; i < item->GetYSize(); ++i) {
		for (uint8 j {0}; j < item->GetXSize(); ++j) {
			if ((i + target_row) >= _gridheight || (j + target_col) >= _gridwidth || tmp_array[get_item_pos(target_row+i,target_col+j)]) {
				PRINT_DEBUG_MESSAGE("item doesn't fit in target");
				return false;
			}
		}
	}
	return true;
}

void UInventoryComponent::SetItem(AItem * item,uint8 row,uint8 column)
{
	if (item) {
		for (uint8 i {row}; i < (row + item->GetYSize()) && i < _gridheight; ++i) {
			for (uint8 j {column}; j < (column + item->GetXSize()) && j < _gridwidth; ++j) {
				set_item(i, j, item);
			}
		}
	}
}

bool UInventoryComponent::CanFit(AItem * item, uint8 & column, uint8 & row) const
{
	if (!item) {
		return false;
	}
	for (uint8 i {0}; i < (_gridheight - (item->GetYSize() - 1)); ++i) {
		for (uint8 j {0}; j < (_gridwidth - (item->GetXSize() - 1)); ++j) {
			if (!get_item(i,j)) {
				bool has_space {true};
				for (uint8 k {i}; k < (i + item->GetYSize()); ++k) {
					for (uint8 l {j}; l < (j + item->GetXSize()); ++l) {
						if (get_item(k,l)) {
							has_space = false;
						}
					}
				}
				if (has_space) {
					row = i;
					column = j;
					return true;
				}
			}
		}
	}
	return false;
}

bool UInventoryComponent::Contains(AItem * item,uint8 & column,uint8 & row) const
{
	if (!item) {
		return false;
	}
	for (uint8 i {0}; i < _gridheight; ++i) {
		for (uint8 j {0}; j < _gridwidth; ++j) {
			if (get_item(i,j) == item) {
				column = j;
				row = i;
				return true;
			}
		}
	}
	return false;
}