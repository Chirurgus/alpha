// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Item.generated.h"

/*
 * An Item, the base class for all items in the game.
 * Implemets Interactable intefrace, this is used to pick items up.
 */
UCLASS()
class ALPHA_API AItem : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	AItem();

	/* Prompts an interact, returns true if interaction was sucessful. */
	bool Interact() override;

	bool CanInteract() override;

	FString GetInteractableName() override;
};
