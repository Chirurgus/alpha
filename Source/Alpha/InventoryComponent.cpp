// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "InventoryComponent.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
	: _grid {}
	, _gridheight {2}
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