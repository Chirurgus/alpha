// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Input/DragAndDrop.h"
#include "UniformGridSlot.h"
#include "InventoryWidget.h"
#include "InventoryDragDropOperation.h"
#include "InventorySlotWidget.h"

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer& obj_init)
	: Super {obj_init}
	, _item {nullptr}
	, DefaultIcon {nullptr}
	, _parent {nullptr}
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> Default_iconObj(
		TEXT("Texture2D'/Game/Item_icons/default_icon.default_icon'")
	);
	DefaultIcon = Default_iconObj.Object;
}

void UInventorySlotWidget::SetParent(UInventoryWidget* w)
{
	_parent = w;
}

void UInventorySlotWidget::SetItem(AItem* const item)
{
	_item = item;
}

AItem * UInventorySlotWidget::GetItem()
{
	return _item;
}

bool UInventorySlotWidget::HandleOnDrop(FGeometry MyGeometry,
										FPointerEvent PointerEvent,
										UDragDropOperation * Operation)
{
	if (UInventoryDragDropOperation* ddop {Cast<UInventoryDragDropOperation>(Operation)}) {
		if (UUniformGridSlot* ugp {Cast<UUniformGridSlot>(Slot)}) {
			bool b {_parent->MoveItem(ddop->GetItem(), ugp->Row, ugp->Column)};
			UE_LOG(ALog, Log,TEXT("Move result: %s"), b ? TEXT("1") : TEXT("0"));
			return b;
		}
	}
	return false;
}

UTexture2D * UInventorySlotWidget::GetIcon() const
{			
	return _item ? _item->GetIcon() : DefaultIcon;
}
