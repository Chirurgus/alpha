// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Equippable.h"


AEquippable::AEquippable()
	: Super {}
	, _owner {nullptr}
{
}

bool AEquippable::Equip(AActor* actor)
{
	if (!CanEquip(actor)) {
		UE_LOG(ALog, Log, TEXT("This actor can't equip this item"));
		return false;
	}
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	_owner = actor;
	return true;
}

bool AEquippable::UnEquip()
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	_owner = nullptr;
	return true;
}

bool AEquippable::CanEquip(AActor* actor)
{
	return actor != nullptr;
}


