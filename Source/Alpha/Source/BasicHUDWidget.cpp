// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Character/CharacterBase.h"
#include "Include/UI/BasicHUDWidget.h"

UBasicHUDWidget::UBasicHUDWidget(const FObjectInitializer& obj_init)
	: Super {obj_init}
{
}

float UBasicHUDWidget::GetPlayerHealth() const
{
	ACharacterBase* pc {Cast<ACharacterBase>(GetOwningPlayerPawn())};
	if (pc) {
		return pc->GetHealth()/1000;
	}
	else {
		return 0.0;
	}
}
