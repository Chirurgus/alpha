// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Item.h"


AItem::AItem()
	: _xsize {1}
	, _ysize {1}
	, _icon {nullptr}
{
}

bool AItem::Interact()
{
	return false;
}

bool AItem::CanInteract()
{
	return false;
}

FString AItem::GetInteractableName()
{
	return FString {"An Item"};
}

uint8 AItem::GetXSize()
{
	return _xsize;
}

uint8 AItem::GetYSize()
{
	return _ysize;
}

UTexture2D * const AItem::GetIcon() const
{
	return _icon;
}
