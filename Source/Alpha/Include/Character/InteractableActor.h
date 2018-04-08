// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Include/Character/VisualActor.h"
#include "Include/Item/Interactable.h"

#include "InteractableActor.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API AInteractableActor : public AVisualActor, public IInteractable
{
	GENERATED_BODY()
public:
	AInteractableActor() {}

	// Interactable interface 
	bool Interact() override { return false; }
	bool CanInteract() override { return false; }
	FString GetInteractableName() { return "Interactable actor"; }
};
