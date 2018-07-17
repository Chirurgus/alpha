// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Include/Character/InteractableActor.h"
#include "DoorActor.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API ADoorActor : public AInteractableActor
{
	GENERATED_BODY()
public:
	bool Interact() override { 
		float rotation {90};
		if (IsOpen) {
			rotation *= -1;
		}

		FHitResult hit{};
		AddActorLocalRotation(
			FRotator{0,rotation,0},
			true,
			&hit,
			ETeleportType::None
		);
		IsOpen = !IsOpen;
		return true;
	}
	bool CanInteract() override { return true; }
	FString GetInteractableName() { return "Door"; }

	UPROPERTY(BlueprintReadOnly, Category= "Enviroment")
	bool IsOpen = false;
};
