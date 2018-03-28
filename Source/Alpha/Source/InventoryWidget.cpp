// Fill out your copyright notice in the Description page of Project Settings.


#include "Include/Alpha.h"

#include "UniformGridSlot.h"

#include "Include/UI/InventoryDragDropOperation.h"
#include "Include/UI/InventoryWidget.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& obj_init)
	: Super {obj_init}
	, _inventory {nullptr}
{
	//Tick is o nly called manually
	bCanEverPaint = false;
}

bool UInventoryWidget::Initialize()
{
	return Super::Initialize() && init_inventory();
}

bool UInventoryWidget::MoveItem(AItem* item, uint8 row, uint8 column)
{
	return _inventory->MoveItem(item, row, column);
}

void UInventoryWidget::ResizeGridPanel(UUniformGridPanel * const grid,
										 const TSubclassOf<UInventorySlotWidget> slot_t)
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
			Cast<UInventorySlotWidget>(slot->Content)->SetParent(this);
			
		}
	}
}
void UInventoryWidget::PopulateGridPanel(UUniformGridPanel * const grid,
										 const TSubclassOf<UInventorySlotWidget> slot_t)
{
	if (_inventory->_grid.Num() != grid->GetChildrenCount())
	{
		grid->ClearChildren();
		ResizeGridPanel(grid, slot_t);
	}
	for (uint8 i {0}; i < _inventory->GetYSize(); ++i) {
		for (uint8 j {0}; j < _inventory->GetXSize(); ++j) {
			UInventorySlotWidget* grid_slot {get_slot(i,j,grid)};
			grid_slot->SetItem(_inventory->get_item(i,j));;
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

