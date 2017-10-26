// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "InventoryDragDropOperation.h"

UInventoryDragDropOperation::UInventoryDragDropOperation()
	: UDragDropOperation {}
{
}

void UInventoryDragDropOperation::SetItem(AItem* item)
{
	_item = item;
}

AItem * UInventoryDragDropOperation::GetItem() const
{
	return _item;
}