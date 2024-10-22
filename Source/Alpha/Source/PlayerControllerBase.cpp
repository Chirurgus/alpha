// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Component/CameraManager.h"

#include "Include/UI/HUDBase.h"
#include "Include/UI/WidgetBase.h"
#include "Include/UI/BasicHUDWidget.h"
#include "Include/UI/PauseMenuWidget.h"

#include "Include/Character/PlayerControllerBase.h"

APlayerControllerBase::APlayerControllerBase()
	: Super{}
{
	IgnoreLookInput = false;
}

void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent) {
		InputComponent->BindAxis("MoveForward", this, &APlayerControllerBase::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &APlayerControllerBase::MoveRight);
		InputComponent->BindAxis("LookUp", this, &APlayerControllerBase::LookUp);
		InputComponent->BindAxis("LookRight", this, &APlayerControllerBase::LookRight);
		InputComponent->BindAction("Jump",IE_Pressed, this, &APlayerControllerBase::JumpPress);
		InputComponent->BindAction("Jump",IE_Released, this, &APlayerControllerBase::JumpRelease);
		InputComponent->BindAction("Shoot",IE_Pressed, this, &APlayerControllerBase::ShootPressed);
		InputComponent->BindAction("Shoot",IE_Released, this, &APlayerControllerBase::ShootReleased);
		InputComponent->BindAction("Crouch",IE_Pressed, this, &APlayerControllerBase::CrouchPressed);
		InputComponent->BindAction("Crouch",IE_Released, this, &APlayerControllerBase::CrouchReleased);
		InputComponent->BindAction("Sprint",IE_Pressed, this, &APlayerControllerBase::SprintPressed);
		InputComponent->BindAction("Sprint",IE_Released, this, &APlayerControllerBase::SprintReleased);
		InputComponent->BindAction("PauseMenu",IE_Pressed, this, &APlayerControllerBase::PauseMenuButtonPressed);
		InputComponent->BindAction("Aim",IE_Pressed, this, &APlayerControllerBase::AimPressed);
		InputComponent->BindAction("Aim",IE_Released, this, &APlayerControllerBase::AimReleased);
		InputComponent->BindAction("Use", IE_Pressed, this, &APlayerControllerBase::InteractPressed);
		InputComponent->BindAction("Use", IE_Released, this, &APlayerControllerBase::InteractReleased);
	}
	else {
		UE_LOG(ALog, Error, TEXT("InputComponent is null"));
	}
}

void APlayerControllerBase::BeginPlay()
{
	AHUDBase* hud {Cast<AHUDBase>(GetHUD())};
	if (hud) {
		if (!hud->IsWidgetInCategory(EUiCategory::HUD, FName {"BasicHUD"})) {
			hud->AddToCategory(
				EUiCategory::HUD,
				FName {"BasicHUD"}
			);
		}
		if (!hud->IsWidgetInCategory(EUiCategory::HUD, FName {"Crosshairs"})) {
			hud->AddToCategory(
				EUiCategory::HUD,
				FName {"Crosshairs"}
			);
		}
		hud->ShowUi(EUiCategory::HUD);
	}
	else {
		UE_LOG(ALog, Warning, TEXT("Can't cast GetHUD() to AHUDBase"));
	}
}

void APlayerControllerBase::Possess(APawn * pawn)
{
	Super::Possess(pawn);
}

void APlayerControllerBase::UnPossess()
{

}

void APlayerControllerBase::LookUp(float v)
{
	if (v != 0) {
		AddPitchInput(-v);	
	}
}

void APlayerControllerBase::LookRight(float v)
{
	if (v != 0) {
		AddYawInput(v);
	}
}

void APlayerControllerBase::MoveForward(float v)
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->MoveForward(v);
	}
}

void APlayerControllerBase::MoveRight(float v)
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->MoveRight(v);
	}
}

void APlayerControllerBase::JumpPress()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp && !cp->IsJumpProvidingForce()) {// same as IsJumping
		cp->JumpPress();
	}
}

void APlayerControllerBase::JumpRelease()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->JumpRelease();
	}
}

void APlayerControllerBase::ShootPressed()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->ShootPressed();
	}
 }

void APlayerControllerBase::ShootReleased()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->ShootReleased();
	}
}

void APlayerControllerBase::InteractPressed()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->InteractPressed();
	}
}

void APlayerControllerBase::InteractReleased()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->InteractReleased();
	}
}

void APlayerControllerBase::CrouchPressed()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->CrouchPressed();
	}
}

void APlayerControllerBase::CrouchReleased()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->CrouchReleased();
	}
}

void APlayerControllerBase::SprintPressed()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->SprintPressed();
	}
}

void APlayerControllerBase::SprintReleased()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->SprintReleased();
	}
}

void APlayerControllerBase::PauseMenuButtonPressed() {
	static bool pause_shown {false};
	//SetPause(!pause_shown);
	SetIgnoreLookInput(!pause_shown);
	SetIgnoreMoveInput(!pause_shown);
	bShowMouseCursor = !pause_shown;
	if (!pause_shown) {
		OpenPauseMenu();
		pause_shown = true;
	}
	else {
		ClosePauseMenu();
		pause_shown = false;
	}
}

void APlayerControllerBase::AimPressed()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->AimPressed();
	}
}

void APlayerControllerBase::AimReleased()
{
	pawn_type* cp {Cast<pawn_type>(GetPawn())};
	if (cp) {
		cp->AimReleased();
	}
}

void APlayerControllerBase::OpenPauseMenu()
{
	AHUDBase* hud {Cast<AHUDBase>(GetHUD())};
	if (hud) {
		if (!hud->IsWidgetInCategory(EUiCategory::PauseMenu, FName {"InventoryMenu"})) {
			hud->AddToCategory(
				EUiCategory::PauseMenu,
				FName {"InventoryMenu"}
			);
		}
		hud->HideUi(EUiCategory::HUD);
		hud->ShowUi(EUiCategory::PauseMenu);
	}
	else {
		UE_LOG(ALog, Warning, TEXT("Can't cast GetHUD() to AHUDBase"));
	}

}

void APlayerControllerBase::ClosePauseMenu()
{
	//SetPause(false);
	AHUDBase* hud {Cast<AHUDBase>(GetHUD())};
	if (hud) {
		hud->HideUi(EUiCategory::PauseMenu);
		hud->ShowUi(EUiCategory::HUD);
	}
	else {
		UE_LOG(ALog, Warning, TEXT("Can't cast GetHUD() to AHUDBase"));
	}

}

