// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Item/GunBase.h"
#include "Include/Character/PlayerCharacter.h"



APlayerCharacter::APlayerCharacter()
	: Super {}
	, _SpringArmComponent
		{CreateDefaultSubobject<USpringArmComponent>("Camera boon component")}
	, _CameraComponent
		{CreateDefaultSubobject<UCameraComponent>("Camera component")}
{
	/* Setup Camera */
	_SpringArmComponent->SetupAttachment(GetRootComponent());
	_SpringArmComponent->bUseControllerViewRotation = true;
	_SpringArmComponent->bInheritPitch = true;
	_SpringArmComponent->bInheritRoll = false;
	_SpringArmComponent->bInheritYaw = true;
	_SpringArmComponent->bEnableCameraLag = false;
	_SpringArmComponent->bEnableCameraRotationLag = false;
	_SpringArmComponent->bUsePawnControlRotation= true;
	_SpringArmComponent->TargetArmLength = 200;
	
	_CameraComponent->SetupAttachment(_SpringArmComponent, USpringArmComponent::SocketName);

	GetCapsuleComponent()->OnComponentBeginOverlap
		.AddDynamic(this, &APlayerCharacter::OnBeginOverlapItem);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	/* Movement */
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
}

void APlayerCharacter::MoveForward(float v)
{
	if (v && Controller) {
		// find out which way is right
		const FRotator rotation {Controller->GetControlRotation()};
		const FRotator yaw_rotation {0, rotation.Yaw, 0};
	
		// get right vector 
		const FVector dir {FRotationMatrix(yaw_rotation).GetUnitAxis(EAxis::X)};
		// add movement in that direction
		AddMovementInput(dir, v);
	}
}

void APlayerCharacter::MoveRight(float v)
{
	if (v && Controller) {
		// find out which way is right
		const FRotator rotation {Controller->GetControlRotation()};
		const FRotator yaw_rotation {0, rotation.Yaw, 0};
	
		// get right vector 
		const FVector dir {FRotationMatrix(yaw_rotation).GetUnitAxis(EAxis::Y)};
		// add movement in that direction
		AddMovementInput(dir, v);
	}
}

void APlayerCharacter::LookUp(float v)
{
	AddControllerPitchInput(-v);
}

void APlayerCharacter::LookRight(float v)
{
	AddControllerYawInput(v);
}

void APlayerCharacter::JumpPress()
{
	/* The actual jump is made via animation Notify */
	_is_jump_pressed = true;
}

void APlayerCharacter::JumpRelease()
{
	_is_jump_pressed = false;
}

void APlayerCharacter::ShootPressed()
{
	AGunBase* gun
		{Cast<AGunBase>(_ActiveInventoryComponent->GetEquippedWeapon())};
	if (gun) {
		gun->Use();
	}
	else {
		UE_LOG(ALog, Log, TEXT("No weapon equipped, can't fire."));
	}

	_is_shoot_pressed = true;
}

void APlayerCharacter::ShootReleased()
{
	_is_shoot_pressed = false;
}


void APlayerCharacter::CrouchPressed()
{
	Crouch();
}

void APlayerCharacter::CrouchReleased()
{
	UnCrouch();
}

void APlayerCharacter::SprintPressed()
{
	_is_sprinting = true;
	GetCharacterMovement()->MaxWalkSpeed = _MaxSprintSpeed;
}

void APlayerCharacter::SprintReleased()
{
	GetCharacterMovement()->MaxWalkSpeed = _MaxWalkSpeed;
	_is_sprinting = false;
}

void APlayerCharacter::AimPressed()
{
	GetCharacterMovement()->bOrientRotationToMovement = false;
	bUseControllerRotationYaw = true;
	FRotator init_r{_SpringArmComponent->GetComponentTransform().GetRotation()};
	FRotator target_r {init_r};
	target_r.Yaw = 0;
	_SpringArmComponent->SetRelativeRotation(FMath::Lerp(init_r, target_r, 0.1f));
	_is_aiming = true;
}

void APlayerCharacter::AimReleased()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
	_is_aiming = false;
}

void APlayerCharacter::OnBeginOverlapItem(UPrimitiveComponent* comp,
										AActor * other_actor,
										UPrimitiveComponent* other_comop,
										int32,
										bool,
										const FHitResult&)
{
	UE_LOG(ALog, Log, TEXT("Overlapping an actor"));
	AWeapon* item {Cast<AWeapon>(other_actor)};
	if (!item) {
		return;	
	}
	if (!_ActiveInventoryComponent->EquipWeapon(item)) {
		_InventoryComponent->Add(item);
	}
}

