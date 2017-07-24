// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "HUDBase.h"

AHUDBase::AHUDBase()
	: Super {}
{
	WidgetBaseClass = UWidgetBase::StaticClass();
}

void AHUDBase::BeginPlay()
{
	Super::BeginPlay();

	_WidgetBase = CreateWidget<UWidgetBase>(GetWorld(), WidgetBaseClass);
	if (_WidgetBase) {
		UE_LOG(ALog, Warning, TEXT("Drawing BasicHUD Widget"));
		_WidgetBase->AddToViewport();
	}
	else {
		UE_LOG(ALog, Warning, TEXT("Could not create BasicHUD Widget"));
	}
}
	
	


