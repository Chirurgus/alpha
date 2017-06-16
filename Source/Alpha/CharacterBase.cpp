// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Engine.h"
#include "GunBase.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Sight.h"
#include "CharacterBase.h"

ACharacterBase::ACharacterBase()
	: Super {}
	, _CameraBoonComponent 
		{CreateDefaultSubobject<USpringArmComponent>("Camera boon component")}
	, _CameraComponent
		{CreateDefaultSubobject<UCameraComponent>("Camera component")}
	, _ActiveInventoryComponent
		{CreateDefaultSubobject<UActiveInventoryComponent>("Active inventory component")}
{ 	
	// Set this character to call Tick() every frame. 
	//You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_CameraBoonComponent->AttachTo(RootComponent);

	_CameraComponent->AttachTo(_CameraBoonComponent);
	
	GetMesh()->SetOwnerNoSee(false);

	this->OnActorBeginOverlap.AddDynamic(this, &ACharacterBase::OnBeginOverlapItem);
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	_Health = 1000;
	
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

// Called every frame
void ACharacterBase::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);

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

void ACharacterBase::ShootPressed()
{
	AGunBase* gun
		{Cast<AGunBase>(_ActiveInventoryComponent->GetEquippedWeapon())};
	if (gun) {
		gun->Use();
	}
	else {
		UE_LOG(ALog, Log, TEXT("No weapon equipped, can't fire."));
	}
}

void ACharacterBase::ShootReleased()
{
}


void ACharacterBase::CrouchPressed()
{
	Crouch();
}

void ACharacterBase::CrouchReleased()
{
	UnCrouch();
}

void ACharacterBase::SprintPressed()
{
	_is_sprinting = true;
	GetCharacterMovement()->MaxWalkSpeed *= 2;
}

void ACharacterBase::SprintReleased()
{
	GetCharacterMovement()->MaxWalkSpeed /= 2;
	_is_sprinting = false;
}

void ACharacterBase::Die()
{
	AController* contoller {GetController()};
	contoller->UnPossess();
	PRINT_DEBUG_MESSAGE("YOU DIED");
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

void ACharacterBase::OnBeginOverlapItem(AActor * my_actor, AActor * other_actor)
{
	UE_LOG(ALog, Log, TEXT("Overlapping an actor"));
	AWeapon* item {Cast<AWeapon>(other_actor)};
	if (!item) {
		return;	
	}
	if (_ActiveInventoryComponent->EquipWeapon(item)) {
		UE_LOG(ALog, Log, TEXT("Weapon equipped successfuly"));
	}
	else {
		UE_LOG(ALog, Log, TEXT("Weapon was not equipped"));
	}
}
