// Fill out your copyright notice in the Description page of Project Settings.


#include "Include/Alpha.h"

#include <Engine.h>

#include "Include/Item/GunBase.h"
#include "Include/Character/CharacterBase.h"

ACharacterBase::ACharacterBase()
	: Super {}
	, _ActiveInventoryComponent
		{CreateDefaultSubobject<UActiveInventoryComponent>("Active inventory component")}
	, _InventoryComponent
		{CreateDefaultSubobject<UInventoryComponent>("Inventory component")}
{ 	
	PrimaryActorTick.bCanEverTick = true;

	_MaxSprintSpeed = 600;
	_MaxWalkSpeed = 300;
	_MaxCrouchSpeed = 200;

	GetCharacterMovement()->MaxWalkSpeedCrouched = _MaxCrouchSpeed;
	GetCharacterMovement()->MaxWalkSpeed = _MaxWalkSpeed;

	GetMesh()->SetOwnerNoSee(false);

}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	_Health = GetMaxHealh();
	
	/*
	UWorld* world {GetWorld()};
	if (world) {
		FActorSpawnParameters sp;
		sp.Owner = this;
		AGunBase* gp {world->SpawnActor<AGunBase>(AGunBase::StaticClass(),
												  GetActorLocation(),
												  GetActorRotation(),
												  sp)};
		if (gp) {
			gp->AttachRootComponentToActor(this);
			_ActiveInventoryComponent->EquipWeapon(gp);
		}
	}
	*/
}

void ACharacterBase::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);

}
float ACharacterBase::GetMaxWalkSpeed() const
{
	return _MaxWalkSpeed;
}

float ACharacterBase::GetMaxSprintSpeed() const
{
	return _MaxSprintSpeed;
}

float ACharacterBase::GetMaxCrouchSpeed() const
{
	return _MaxCrouchSpeed;
}

bool ACharacterBase::IsJumpPressed()
{
	return _is_jump_pressed;
}

bool ACharacterBase::IsShootPressed() const
{
	return _is_shoot_pressed;
}

UInventoryComponent * ACharacterBase::GetInventoryComponent()
{
	return _InventoryComponent;
}

float ACharacterBase::GetHealth() const
{
	return _Health;
}

float ACharacterBase::GetMaxHealh() const
{
	return 1000.0f;
}

void ACharacterBase::Die()
{
	PRINT_DEBUG_MESSAGE("YOU DIED");
	PRINT_DEBUG_MESSAGE("OH, DON'T CRY, HERE, HAVE ANOTHER TRY!");
	_Health = GetMaxHealh();
}

bool ACharacterBase::IsAiming() const
{
	return _is_aiming;
}

float ACharacterBase::TakeDamage(float damage,const FDamageEvent&,AController*,AActor*)
{
	if (damage) {
		_Health -= damage;	
		if (_Health <= 0) {
			Die();	
		}
	}
	return damage;
}

float ACharacterBase::TakeDamageTest(float damage)
{
	if (damage) {
		_Health -= damage;	
		if (_Health <= 0) {
			Die();	
		}
	}
	return damage;
}

