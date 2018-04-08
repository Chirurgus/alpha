// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Character/InteractableButton.h"

AInteractableButton::AInteractableButton()
{
	InteractableName = "Button";
}

AInteractableButton::FPressedEvent & AInteractableButton::OnPressed()
{
	return _ButtonPressedEvent;
}

bool AInteractableButton::Interact()
{
	_ButtonPressedEvent.Broadcast();
	return true;
}

bool AInteractableButton::CanInteract()
{
	return true;
}

FString AInteractableButton::GetInteractableName()
{
	return InteractableName;
}
