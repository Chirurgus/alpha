// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
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

void ACharacterBase::WalkForward(float v)
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

void ACharacterBase::WalkRight(float v)
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

}

void ACharacterBase::LookRight(float v)
{

}

void ACharacterBase::JumpPress()
{

}

void ACharacterBase::JumpRelease()
{

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

