// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "GunProjectile.h"


// Sets default values
AGunProjectile::AGunProjectile()
	: Super{}
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AGunProjectile::AGunProjectile(const FObjectInitializer& obj_init)
	: Super{obj_init}
{
	_capsule_comp = obj_init.CreateDefaultSubobject<USphereComponent>(this, "ShpereComponent");		
	_capsule_comp->InitSphereRadius(5.0f);
	
	_mvm_comp = obj_init.CreateAbstractDefaultSubobject<UProjectileMovementComponent>(this, "MovementComponent");
	_mvm_comp->InitialSpeed = 10000.0f;
	_mvm_comp->SetUpdatedComponent(_capsule_comp);
	_mvm_comp->MaxSpeed = 20000.0f;
	_mvm_comp->bRotationFollowsVelocity = true;
	_mvm_comp->bShouldBounce = false;
}
// Called when the game starts or when spawned
void AGunProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGunProjectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AGunProjectile::InitVelocity(const FVector& dir)
{
	if (_mvm_comp) {
		_mvm_comp->Velocity = _mvm_comp->InitialSpeed * dir;
	}
}

