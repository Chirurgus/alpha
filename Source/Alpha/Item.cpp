// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Item.h"


AItem::AItem()
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
