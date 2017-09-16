// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "UniformGridSlot.h"
#include "CharacterBase.h"
#include "InventoryGridPanel.h"

UInventoryGridPanel::UInventoryGridPanel(const FObjectInitializer& obj_init)
	: Super {obj_init}
	, _inventory {nullptr}
{
}

void UInventoryGridPanel::PostLoad()
{
	Super::PostLoad();
	Resize();
	PRINT_DEBUG_MESSAGE("hi");
}

void UInventoryGridPanel::Resize()
{
	APlayerController* controller {GetOwningPlayer()};//GetWorld()->GetFirstPlayerController()};
	if (!controller) {
		UE_LOG(ALogCritical, Error, TEXT("GetOwningPlayer is null"));
		return;
	}
	ACharacterBase* pc {Cast<ACharacterBase>(controller->GetPawn())};
	if (!pc) {
		UE_LOG(ALogCritical, Error, TEXT("InventoryGridPanel is not owned by ACharacterBase"));
		return;
	}

	_inventory = pc->GetInventoryComponent();
	for (uint8 i {0}; i < _inventory->GetYSize(); ++i) {
		for (uint8 j {0}; j < _inventory->GetXSize(); ++j) {
			UUniformGridSlot* slot {
				AddChildToUniformGrid(CreateWidget<UWidgetBase>(controller, GridSlotType))
			};
			if (!slot) {
				UE_LOG(ALog, Log, TEXT("AddChildToUniformGrid returned nullptr"));
				return;
			}
			slot->SetColumn(j);
			slot->SetRow(i);
		}
	}
}
