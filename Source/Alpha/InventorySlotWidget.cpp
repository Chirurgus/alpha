// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "InventorySlotWidget.h"

UInventorySlotWidget::UInventorySlotWidget(const FObjectInitializer& obj_init)
	: Super {obj_init}
	, _icon {nullptr}
{
}

void UInventorySlotWidget::SetIcon(UTexture2D * const icon)
{
	_icon = icon;
}

UTexture2D * const UInventorySlotWidget::GetIcon() const
{
	return _icon;
}
