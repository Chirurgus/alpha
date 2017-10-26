// Fill out your copyright notice in the Description page of Project Settings.
#include "Alpha.h"
#include "InventoryComponent.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
	: _grid {}
	, _gridheight {2}
	, _gridwidth {2}
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
			set_item(y + i,x + j,nullptr);
		}
	}
	
}

bool UInventoryComponent::CanFit(AItem * item)
{	
	uint8 x,y;
	return CanFit(item, x, y);
}

bool UInventoryComponent::Contains(AItem * item)
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

bool UInventoryComponent::MoveItem(AItem * item, const uint8 j_target, const uint8 i_target)
{
	if (CanMove(item,j_target,i_target)) {
		Remove(item);
		if (AItem* target_item {get_item(j_target,i_target)}) {
			uint8 item_j, item_i;
			Contains(item, item_i, item_j);
			uint8 target_item_j, target_item_i;
			Contains(target_item,target_item_j,target_item_i);
			Remove(target_item);
			SetItem(item, j_target, i_target);
			SetItem(target_item, item_j, item_i);
		}
		else {
			set_item(j_target,i_target,item);
		}
		return true;
	}
	return false;
}

bool UInventoryComponent::CanMove(AItem * item, const uint8 j_target, const uint8 i_target)
{
	/* TODO: check if swaping is possible

	*/
	/*
	{
		FString a {"j_target = "}; 
		a += (j_target == 1 ? "1" : "0");
		FString b {"i_target = "};
		b += (j_target == 1 ? "1" : "0");
		PRINT_DEBUG_MESSAGE(a);
		PRINT_DEBUG_MESSAGE(b);
	}
	PRINT_DEBUG_MESSAGE("=============================");
	for (uint8 i {_gridheight}; i-- > 0;) {
		FString s {};
		for (uint8 j {0}; j < _gridwidth; ++j) {
			s += (get_item(i,j) ? "1 " : "0 ");
		}
		PRINT_DEBUG_MESSAGE(s);
	}
	*/

	uint8 item_i_pos {}, item_j_pos {};

	if (!item) PRINT_DEBUG_MESSAGE("PTR Null");
	if (j_target >= _gridwidth) PRINT_DEBUG_MESSAGE("j too big");
	if (i_target >= _gridheight) PRINT_DEBUG_MESSAGE("I too big");
	if (!Contains(item, item_j_pos, item_i_pos)) PRINT_DEBUG_MESSAGE("dose not contain item");

	if (!item ||
		j_target >= _gridwidth ||
		i_target >= _gridheight ||
		!Contains(item, item_j_pos, item_i_pos))
	{
		PRINT_DEBUG_MESSAGE("HI");
		PRINT_DEBUG_MESSAGE("=============================");
		for (uint8 i {_gridheight}; i-- > 0;) {
			FString s {};
			for (uint8 j {0}; j < _gridwidth; ++j) {
				s += (get_item(i,j) ? "1 " : "0 ");
			}
			PRINT_DEBUG_MESSAGE(s);
		}
		return false;
	}
	TArray<AItem*> tmp_array(_grid);
	for (auto& p : tmp_array) {
		if (p == item) {
			p = nullptr;
		}
	}
	if (AItem* target_item {tmp_array[get_item_pos(j_target,i_target)]}) {
		for (auto& p : tmp_array) {
			if (p == target_item) {
				p = nullptr;
			}
		}
		for (uint8 i {0}; i < item->GetYSize(); ++i) {
			for (uint8 j {0}; j < item->GetXSize(); ++j) {
				if (!(i >= _gridwidth || j >= _gridheight) || tmp_array[get_item_pos(j_target+j,i_target+i)]) {
					return false;
				}
			}
		}
	}
	for (uint8 i {0}; i < item->GetYSize(); ++i) {
		for (uint8 j {0}; j < item->GetXSize(); ++j) {
			if (!(i >= _gridwidth || j >= _gridheight) || tmp_array[get_item_pos(j_target+j,i_target+i)]) {
				return false;
			}
		}
	}
	return true;
}

void UInventoryComponent::SetItem(AItem * item,uint8 row,uint8 column)
{
	if (item) {
		for (uint8 i {column}; i < (column + item->GetYSize()) && i < _gridwidth; ++i) {
			for (uint8 j {row}; j < (row + item->GetXSize()) && j < _gridheight; ++j) {
				set_item(j, i, item);
			}
		}
	}
}

bool UInventoryComponent::CanFit(AItem * item, uint8 & x, uint8 & y)
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
					y = i;
					x = j;
					return true;
				}
			}
		}
	}
	return false;
}

bool UInventoryComponent::Contains(AItem * item,uint8 & x,uint8 & y)
{
	if (!item) {
		return false;
	}
	for (uint8 i {0}; i < _gridheight; ++i) {
		for (uint8 j {0}; j < _gridwidth; ++j) {
			if (get_item(i,j) == item) {
				x = j;
				y = i;
				return true;
			}
		}
	}
	return false;
}