// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "AlphaCharacter.h"
#include "CharacterBase.h"
#include "TestPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API ATestPlayerController : public APlayerController
{
	GENERATED_BODY()

	ATestPlayerController();
	
	void SetupInputComponent() override;

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

private:
	using pawn_type = ACharacterBase;
};
