// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"

#include "PlayerCharacter.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ALPHA_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

	APlayerControllerBase();

	void SetupInputComponent() override;
	
	void BeginPlay() override;
	void Possess(APawn* pawn) override;
	void UnPossess() override;

	void MoveForward(float v);
	void MoveRight(float v);
	void JumpPress();
	void JumpRelease();
	void LookUp(float v);
	void LookRight(float v);
	void ShootPressed();
	void ShootReleased();
	void CrouchPressed();
	void CrouchReleased();
	void SprintPressed();
	void SprintReleased();
	void PauseMenuButtonPressed();
	void AimPressed();
	void AimReleased();
	void InteractPressed();
	void InteractReleased();

protected:

private:
	void OpenPauseMenu();
	void ClosePauseMenu();

	using pawn_type = APlayerCharacter;
};
