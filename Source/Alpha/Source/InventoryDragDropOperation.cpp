// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/UI/InventoryDragDropOperation.h"

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