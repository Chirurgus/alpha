// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "AlphaCharacter.h"
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

	//Looking around?????
private:
	using pawn_type = AAlphaCharacter;
};
