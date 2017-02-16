// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "TestPlayerController.h"

ATestPlayerController::ATestPlayerController()
	: Super{}
{
}

void ATestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent) {
		InputComponent->BindAxis("MoveForward", this, &ATestPlayerController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &ATestPlayerController::MoveRight);
		InputComponent->BindAxis("LookUp", this, &ATestPlayerController::LookUp);
		InputComponent->BindAxis("LookRight", this, &ATestPlayerController::LookRight);
		InputComponent->BindAction("Jump",IE_Pressed, this, &ATestPlayerController::JumpPress);
		InputComponent->BindAction("Jump",IE_Released, this, &ATestPlayerController::JumpRelease);
		InputComponent->BindAction("Shoot",IE_Pressed, this, &ATestPlayerController::ShootPressed);
		InputComponent->BindAction("Shoot",IE_Released, this, &ATestPlayerController::ShootReleased);
		InputComponent->BindAction("Crouch",IE_Pressed, this, &ATestPlayerController::CrouchPressed);
		InputComponent->BindAction("Crouch",IE_Released, this, &ATestPlayerController::CrouchReleased);
		InputComponent->BindAction("Sprint",IE_Pressed, this, &ATestPlayerController::SprintPressed);
		InputComponent->BindAction("Sprint",IE_Released, this, &ATestPlayerController::SprintReleased);

	}
	//TODO: Handle if InputComponent is null
}

void ATestPlayerController::LookUp(float v)
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->LookUp(v);
	}
}

void ATestPlayerController::LookRight(float v)
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->LookRight(v);
	}
}

void ATestPlayerController::MoveForward(float v)
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->MoveForward(v);
	}
}

void ATestPlayerController::MoveRight(float v)
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->MoveRight(v);
	}
}

void ATestPlayerController::JumpPress()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp && !cp->IsJumpProvidingForce()) {// same as IsJumping
		cp->Jump();
	}
}

void ATestPlayerController::JumpRelease()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->JumpRelease();
	}
}

void ATestPlayerController::ShootPressed()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->ShootPressed();
	}
 }

void ATestPlayerController::ShootReleased()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->ShootReleased();
	}
}

void ATestPlayerController::CrouchPressed()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->CrouchPressed();
	}
}

void ATestPlayerController::CrouchReleased()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->CrouchReleased();
	}
}

void ATestPlayerController::SprintPressed()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->SprintPressed();
	}
}

void ATestPlayerController::SprintReleased()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->SprintReleased();
	}
}
