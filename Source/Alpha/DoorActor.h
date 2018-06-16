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
		FHitResult hit{};
		_Mesh->AddRelativeRotation(
			FRotator{0,90,0},
			true,
			&hit,
			ETeleportType::None
		);
		return true;
	}
	bool CanInteract() override { return true; }
	FString GetInteractableName() { return "Door"; }
	
	
};
