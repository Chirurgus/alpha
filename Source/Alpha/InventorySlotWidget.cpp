// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "InventorySlotWidget.h"

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer& obj_init)
	: Super {obj_init}
	, _item {nullptr}
	, DefaultIcon {nullptr}
{
	static ConstructorHelpers::FObjectFinder<UTexture2D> Default_iconObj(
		TEXT("Texture2D'/Game/Item_icons/default_icon.default_icon'")
	);
	DefaultIcon = Default_iconObj.Object;
}

void UInventorySlotWidget::SetItem(AItem* const item)
{
	_item = item;
}

AItem * UInventorySlotWidget::GetItem()
{
	return _item;
}

UTexture2D * UInventorySlotWidget::GetIcon() const
{			
	return _item ? _item->GetIcon() : DefaultIcon;
}
