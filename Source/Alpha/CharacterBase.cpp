// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Engine.h"
#include "CharacterBase.h"


// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACharacterBase::MoveForward(float v)
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

void ACharacterBase::MoveRight(float v)
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

void ACharacterBase::LookUp(float v)
{
	AddControllerPitchInput(-v);
}

void ACharacterBase::LookRight(float v)
{
	AddControllerYawInput(v);
}

void ACharacterBase::JumpPress()
{
	Jump();
}

void ACharacterBase::JumpRelease()
{
	StopJumping();
}

void ACharacterBase::Shoot()
{
	FVector camera_pos{};
	FRotator camera_rot{};
	GetActorEyesViewPoint(camera_pos, camera_rot);
	const FRotator muzzle_rot {camera_rot};
	const FVector muzzle_pos {camera_pos + FTransform(camera_rot).TransformVector(_muzzle_offset)};
	UWorld* const world {GetWorld()};
	if (world) {
		FActorSpawnParameters spawn_param;
		spawn_param.Owner = this;
		spawn_param.Instigator = Instigator;
		// spawn the projectile at the muzzle
		AGunProjectile* const projectile {world->SpawnActor<AGunProjectile>(_projectile_type, muzzle_pos, muzzle_rot, spawn_param)};
		if (projectile)
		{
			// find launch direction
			projectile->InitVelocity(muzzle_rot.Vector());
		}
	}
}