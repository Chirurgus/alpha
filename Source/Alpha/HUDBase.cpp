// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "BasicHUDWidget.h"
#include "HUDBase.h"

AHUDBase::AHUDBase()
	: Super {}
	, RegisteredWidgetClasses {}
	, _HUDWidgets {}
	, _PauseMenuWidgets {}
	, _EscMenuWidgets {}
{
}
	
bool AHUDBase::ShowUi(EUiCategory category)
{
	TArray<UWidgetBase*>& widget_array {getWidgetArray(category)};

	for (UWidgetBase* w : widget_array) {
		w->AddToViewport();
	}

	return true;
}

bool AHUDBase::HideUi(EUiCategory category)
{
	TArray<UWidgetBase*>& widget_array {getWidgetArray(category)};

	for (auto* w : widget_array) {
		w->RemoveFromViewport();
	}
	
	return true;
}
	

bool AHUDBase::AddToCategory(EUiCategory category, FName type)
{
	TSubclassOf<UWidgetBase> widget_type {GetRegisteredWidgetClass(type)};

	if (!widget_type) {
		return false;
	}
	UWidgetBase* widget {
		CreateWidget<UWidgetBase>(GetOwningPlayerController(), widget_type)
	};
	TArray<UWidgetBase*>& widget_array {getWidgetArray(category)};

	widget_array.Add(widget);

	return true;
}
	

bool AHUDBase::RemoveFromCategory(EUiCategory category, FName type)
{
	TSubclassOf<UWidgetBase> widget_type {GetRegisteredWidgetClass(type)};

	if (!widget_type) {
		return false;
	}

	TArray<UWidgetBase*>& widget_array {getWidgetArray(category)};

	for (auto it {widget_array.CreateIterator()}; it; ++it) {
		if ((*it)->IsA(widget_type)) {
			(*it)->RemoveFromViewport();
			widget_array.RemoveAt(it.GetIndex());
			break;
		}
	}

	return true;
}

bool AHUDBase::IsWidgetInCategory(EUiCategory category, FName type)
{
	TSubclassOf<UWidgetBase> widget_type {GetRegisteredWidgetClass(type)};

	if (!widget_type) {
		return false;
	}

	TArray<UWidgetBase*>& widget_array {getWidgetArray(category)};

	for (auto it {widget_array.CreateIterator()}; it; ++it) {
		if ((*it)->IsA(widget_type)) {
			return true;
		}
	}

	return false;
}
	

bool AHUDBase::RemoveLastFromCategory(EUiCategory category)
{
	TArray<UWidgetBase*>& widget_array {getWidgetArray(category)};

	UWidgetBase* widget = widget_array.Pop(true);
	widget->RemoveFromViewport();

	return true;
}

void AHUDBase::RegisterWidgetClass(FName class_name, UClass * to_register)
{
	RegisteredWidgetClasses.Add(class_name, to_register);
}

TSubclassOf<UWidgetBase> AHUDBase::GetRegisteredWidgetClass(FName registered_class)
{
	TSubclassOf<UWidgetBase>* ret {RegisteredWidgetClasses.Find(registered_class)};
	return ret ? *ret : nullptr;
}

void AHUDBase::UnRegisterWidgetClass(FName registered_class)
{
	if (GetRegisteredWidgetClass(registered_class)) {
		RegisteredWidgetClasses.Remove(registered_class);
	}
}

TArray<UWidgetBase*>& AHUDBase::getWidgetArray(EUiCategory category)
{
	switch (category) {
	case EUiCategory::HUD :
		return _HUDWidgets;
	case EUiCategory::PauseMenu :
		return _PauseMenuWidgets;
	//case EUiCategory::EscMenu :
	default:
		return _EscMenuWidgets;
	}
}
