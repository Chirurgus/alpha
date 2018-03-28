//Copyright goes here

#pragma once

#include "Interactable.generated.h"

/*
 * Inteface for all interactable items in the game.
 * everything, such as Items, doors, and other characters that the player is
 * able to interact with is Interactable via this interface.
 */
UINTERFACE()
class ALPHA_API UInteractable : public UInterface {
	GENERATED_BODY()

public:
	UInteractable();
};

class IInteractable {
	GENERATED_BODY()

public:
	/* Perform interaction, returns true if interaction was successful,
	 * or false otherwise.
	 */
	UFUNCTION()
	virtual bool Interact() = 0;

	/* Check if this can be interacted with
	 * The following behavior is expected:
	 *		CanInteract() == true => Interact() == true
	 */
	UFUNCTION()
	virtual bool CanInteract() = 0;

	/* Get the name of the object that the player wants to interact with,
	 * should be used for on-screen indication what player is about to interact
	 * with.
	 */
	UFUNCTION()
	virtual FString GetInteractableName() = 0;
};