// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "CameraManager.h"
#include "PlayerControllerBase.h"

APlayerControllerBase::APlayerControllerBase()
	: Super{}
	, _CameraActor {nullptr}
	/*
	, _CameraComponent {CreateDefaultSubobject<UCameraComponent>("Camera Component")}
	, _SpringArmComponent {CreateDefaultSubobject<USpringArmComponent>("Spring arm component")}
	*/
{
	SetupCamera();

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

	}
	//TODO: Handle if InputComponent is null
}

void APlayerControllerBase::Possess(APawn * pawn)
{
	Super::Possess(pawn);
	if (!_CameraActor) {
		UWorld* world {GetWorld()};
		if (!world) {
			UE_LOG(ALog, Warning, TEXT("Could not spawn camera, GetWorld() is null."));
			return;
		}

		FActorSpawnParameters spawn_param;
		spawn_param.Owner = this;
		spawn_param.Instigator = pawn;
		spawn_param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		_CameraActor = world->SpawnActor<AThirdPersonCameraActor>(
			pawn->GetActorLocation(),
			pawn->GetActorRotation(),
			spawn_param);
		if (!_CameraActor) {
			UE_LOG(ALog, Warning, TEXT("Could not spawn camera, GetWorld() is null."));
			return;
		}
	}
	_CameraActor->AttachRootComponentToActor(pawn);
	_CameraActor->SetActorRelativeLocation(FVector {0, 0, 80});
	//PlayerCameraManager->SetViewTarget(_CameraActor, FViewTargetTransitionParams {});
	PlayerCameraManager->ViewTarget.Target = _CameraActor;
}

void APlayerControllerBase::UnPossess()
{
	/* TODO:
		Maybe this should be handled differently, perhaps, the actor
		sould be unspawned.
	*/
	_CameraActor = nullptr;
}

void APlayerControllerBase::SetupCamera()
{
	//PlayerCameraManagerClass = ACameraManager::StaticClass();

	/*
	_SpringArmComponent->SetupAttachment(RootComponent);
	_CameraComponent->SetupAttachment(_SpringArmComponent);

	_SpringArmComponent->TargetArmLength = 300;
	*/
}

void APlayerControllerBase::LookUp(float v)
{
	if (v != 0) {
		//See "Fix the 3rd person camers" issue discussion for explanation.
		//AddPitchInput(v);	
		_CameraActor->AddActorLocalRotation(FRotator {InputPitchScale * -v, 0, 0});
	}
}

void APlayerControllerBase::LookRight(float v)
{
	if (v != 0) {
		AddYawInput(v);
		//_CameraActor->AddActorLocalRotation(FRotator {0, InputYawScale * v, 0});
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
		cp->Jump();
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
