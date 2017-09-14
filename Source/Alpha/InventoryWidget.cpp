// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "InventoryGridPanel.h"
#include "InventoryWidget.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& obj_init)
	: Super {obj_init}
	, _inventory {nullptr}
{
}

bool UInventoryWidget::Initialize()
{
	bool ret {Super::Initialize()};
	ACharacterBase* pc {Cast<ACharacterBase>(GetOwningPlayerPawn())};
	if (pc) {
		_inventory = pc->GetInventoryComponent();
	}
	else {
		UE_LOG(ALogCritical, Error, TEXT("InventoryWidget is not owned by ACharacterBase"));
	}
	return ret;
}

uint8 UInventoryWidget::GetXSize() const
{
	return _inventory ? _inventory->GetXSize() : 0;
}

uint8 UInventoryWidget::GetYSize() const
{
	return _inventory ? _inventory->GetYSize() : 0;
}

UInventoryComponent * UInventoryWidget::GetInventoryComponent()
{
	return _inventory;
}

