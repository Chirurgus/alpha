// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Item/Equippable.h"


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
	
	_owner = actor;
	SetActorEnableCollision(false);
	AttachToComponent(Cast<ACharacter>(_owner)->GetMesh(),
					  FAttachmentTransformRules::KeepRelativeTransform,
					  "RightHandSocket");
	SetActorRelativeLocation(FVector {0,0,0});
	
	return true;
}

bool AEquippable::UnEquip()
{
	SetActorEnableCollision(true);
	_owner = nullptr;
	return true;
}

bool AEquippable::CanEquip(AActor* actor) const
{
	return !IsEquipped() && actor != nullptr;
}

bool AEquippable::IsEquipped() const
{
	return _owner != nullptr;
}


AActor* AEquippable::GetItemOwner() const
{
	return _owner;
}
