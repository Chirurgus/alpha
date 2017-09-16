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

void UInventoryWidget::PopulateGridPanel(UUniformGridPanel * const grid,
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
			slot->SetColumn(j);
			slot->SetRow(i);
		}
	}
}

/*
UInventoryComponent * UInventoryWidget::GetInventoryComponent()
{
	return _inventory;
}
*/

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

