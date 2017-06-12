//Copyright goes here

#pragma once

#include "Interactable.generated.h"

UINTERFACE()
class ALPHA_API UInteractable : public UInterface {
	GENERATED_BODY()

public:
	UInteractable();
};

class IInteractable {
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual bool Interact() = 0;

	UFUNCTION()
	virtual bool CanInteract() = 0;

	UFUNCTION()
	virtual FString GetInteractableName() = 0;
};