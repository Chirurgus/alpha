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
	, _MaxTraceDistance {400}
	, _focus_actor {nullptr}
{
	/* Setup Camera */
	_SpringArmComponent->SetupAttachment(GetRootComponent());
	_SpringArmComponent->bUsePawnControlRotation = true;
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

void APlayerCharacter::Tick(float delta)
{
	AInteractableActor* hit {RaytraceInteractableActor()};
	if (_focus_actor && hit != _focus_actor) {
		_focus_actor->OnEndFocus();
	}
	_focus_actor = hit;
	if (hit) {
		PRINT_DEBUG_MESSAGE(hit->GetInteractableName());
		hit->OnFocus();
	}
}

// Implimentation from "Survival sample game"
AInteractableActor* APlayerCharacter::RaytraceInteractableActor()
{
    if (!GetController()) {
        return nullptr;
	}

	FVector location {};
	FRotator rotation {};

    GetController()->GetPlayerViewPoint(location, rotation);

    FCollisionQueryParams trace_params {
		FName(TEXT("TraceInteractableActor")), true, this
	};
    trace_params.bTraceAsyncScene = true;
    trace_params.bReturnPhysicalMaterial = false;
    trace_params.bTraceComplex = true;

    // FHitResults is passed in with the trace function and holds the result of the trace.
    FHitResult hit(EForceInit::ForceInit);
    GetWorld()->LineTraceSingleByChannel(
		hit,// result
		location,// Trace begin
		location + (_MaxTraceDistance * rotation.Vector()),// Trace end
		ECC_Visibility,// Collision chanel
		trace_params,
		FCollisionResponseParams::DefaultResponseParam
	);

    // Uncomment this to visualize your line during gameplay. */
    //DrawDebugLine(GetWorld(), location,
	//	location + (_MaxTraceDistance * rotation.Vector()),
	//	FColor::Red, false, 1.0f );


    return Cast<AInteractableActor>(hit.GetActor());
}

void APlayerCharacter::MoveForward(float v)
{
	if (v && Controller) {
		// find out which way is right
		const FRotator rotation {Controller->GetControlRotation()};
		const FRotator yaw_rotation {0, rotation.Yaw, 0};
	
		// get right vector 
		const FVector dir {FRotationMatrix(yaw_rotation).GetUnitAxis(EAxis::X)};

		if (CoverComponent->IsInCover()) {
			AddMovementInput(CoverComponent->GetCoverMovementDirection() * FVector::DotProduct(dir, CoverComponent->GetCoverMovementDirection()), v);
		}
		else {
			AddMovementInput(dir, v);
		}
		// add movement in that direction
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
		if (CoverComponent->IsInCover()) {
			AddMovementInput(CoverComponent->GetCoverMovementDirection() * FVector::DotProduct(dir, CoverComponent->GetCoverMovementDirection()), v);
		}
		else {
			AddMovementInput(dir, v);
		}
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

void APlayerCharacter::InteractPressed()
{
	if (auto actor {RaytraceInteractableActor()}) {
		actor->Interact();
	}
}

void APlayerCharacter::InteractReleased()
{
}

void APlayerCharacter::CrouchPressed()
{
	Crouch();
	if (CoverComponent->GetCanTakeCover()) {
		CoverComponent->SetInCover(true);
		PRINT_DEBUG_MESSAGE("TAKING COVER!");
	}
}

void APlayerCharacter::CrouchReleased()
{
	CoverComponent->SetInCover(false);
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

