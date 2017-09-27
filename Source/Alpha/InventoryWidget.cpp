// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "UniformGridSlot.h"
#include "InventoryWidget.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& obj_init)
	: Super {obj_init}
	, _inventory {nullptr}
{
}

bool UInventoryWidget::Initialize()
{
	return Super::Initialize() && init_inventory();
}

void UInventoryWidget::ResizeGridPanel(UUniformGridPanel * const grid,
										 const TSubclassOf<UWidgetBase> slot_t) const
{
	for (uint8 i {0}; i < _inventory->GetYSize(); ++i) {
		for (uint8 j {0}; j < _inventory->GetXSize(); ++j) {
			UUniformGridSlot* const slot {
				grid->AddChildToUniformGrid(
					CreateWidget<UWidgetBase>(GetOwningPlayer(), slot_t)
				)
			};
			if (!slot) {
				UE_LOG(ALog, Error, TEXT("AddChildToUniformGrid returned nullptr"));
				return;
			}
			slot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
			slot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
			slot->SetColumn(j);
			slot->SetRow(i);
		}
	}
}
void UInventoryWidget::PopulateGridPanel(UUniformGridPanel * const grid,
										 const TSubclassOf<UWidgetBase> slot_t) const
{
	/* if grid is not of appropriate size */
	/*
	if (_inventory->_grid.Num() != grid->GetChildrenCount() ||
		Cast<UUniformGridSlot>(grid->GetChildAt(grid->GetChildrenCount() - 1))->Row
		!= _inventory->GetYSize() - 1 ||
		Cast<UUniformGridSlot>(grid->GetChildAt(grid->GetChildrenCount() - 1))->Column
		!= _inventory->GetXSize() - 1)
		*/
	{
		grid->ClearChildren();
		ResizeGridPanel(grid, slot_t);
		PRINT_DEBUG_MESSAGE("CALLLLLLLLLLLLED");
	}
	for (uint8 i {0}; i < _inventory->GetYSize(); ++i) {
		for (uint8 j {0}; j < _inventory->GetXSize(); ++j) {
			get_slot(i,j,grid)->SetItem(_inventory->get_item(i,j));;
		}
	}
}

inline UInventorySlotWidget* UInventoryWidget::get_slot(const uint8 y,
								    const uint8 x,
								    UUniformGridPanel* const grid) const
{
	return Cast<UInventorySlotWidget>(grid->GetChildAt(_inventory->get_item_pos(y, x)));
}


bool UInventoryWidget::init_inventory()
{
	ACharacterBase* pc {Cast<ACharacterBase>(GetOwningPlayerPawn())};
	if (pc) {
		_inventory = pc->GetInventoryComponent();
		return true;
	}
	else {
		UE_LOG(ALogCritical, Error, TEXT("Could not initialize InventoryWidget"));
		return false;
	}
}

