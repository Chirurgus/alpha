// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Include/Character/InteractableActor.h"

#include "InteractableButton.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API AInteractableButton : public AInteractableActor
{
	GENERATED_BODY()
public:
	AInteractableButton();

	// Event for a button press
	DECLARE_EVENT(AInteractableButton, FPressedEvent)
	FPressedEvent& OnPressed();

	// Interactable interface 
	bool Interact() override;
	bool CanInteract() override;
	FString GetInteractableName() override;
	
protected:
	// Name to be shown to the player 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button")
	FString InteractableName;

private:
	FPressedEvent _ButtonPressedEvent;
};