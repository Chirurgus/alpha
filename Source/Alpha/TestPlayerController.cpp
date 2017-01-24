// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "TestPlayerController.h"

ATestPlayerController::ATestPlayerController()
	: Super()
{
}

void ATestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent) {
		InputComponent->BindAxis("MoveForward", this, &ATestPlayerController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &ATestPlayerController::MoveRight);
		InputComponent->BindAction("Jump",IE_Pressed, this, &ATestPlayerController::JumpPress);
		InputComponent->BindAction("Jump",IE_Released, this, &ATestPlayerController::JumpRelease);
	}
	//TODO: Handle if InputComponent is null
}

void ATestPlayerController::MoveForward(float v)
{
	AAlphaCharacter* cp {Cast<AAlphaCharacter>(GetPawn())};
	if (cp) {
		cp->MoveForward(v);
	}
}

void ATestPlayerController::MoveRight(float v)
{
	AAlphaCharacter* cp {Cast<AAlphaCharacter>(GetPawn())};
	if (cp) {
		cp->MoveRight(v);
	}
}

void ATestPlayerController::JumpPress()
{
	AAlphaCharacter* cp {Cast<AAlphaCharacter>(GetPawn())};
	if (cp && !cp->IsJumping()) {
		cp->Jump();
	}
}

void ATestPlayerController::JumpRelease()
{
}
