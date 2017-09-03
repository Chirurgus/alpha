// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Item.h"


AItem::AItem()
	: _xsize {1}
	, _ysize {1}
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

inline uint8 AItem::GetXSize()
{
	return _xsize;
}

inline uint8 AItem::GetYSize()
{
	return _ysize;
}
