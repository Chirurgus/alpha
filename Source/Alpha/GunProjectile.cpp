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
	_SphereComponent = obj_init.CreateDefaultSubobject<USphereComponent>(this, "ShpereComponent");		
	_SphereComponent->InitSphereRadius(5.0f);
	
	_MovementComponent = obj_init.CreateAbstractDefaultSubobject<UProjectileMovementComponent>(this, "MovementComponent");
	//_mvm_comp->InitialSpeed = 00000.0f;
	_MovementComponent->SetUpdatedComponent(_SphereComponent);
	_MovementComponent->InitialSpeed = 100.0f;
	_MovementComponent->MaxSpeed = 20000.0f;
	_MovementComponent->bRotationFollowsVelocity = true;
	_MovementComponent->bShouldBounce = false;
 /*
 _mvm_comp = obj_init.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
    _mvm_comp->UpdatedComponent = _capsule_comp;
    _mvm_comp->InitialSpeed = 3000.f;
    _mvm_comp->MaxSpeed = 3000.f;
    _mvm_comp->bRotationFollowsVelocity = true;
    _mvm_comp->bShouldBounce = true;
    _mvm_comp->Bounciness  = 0.3f;
	*/
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
	if (_MovementComponent) {
		_MovementComponent->Velocity = _MovementComponent->InitialSpeed * dir;
	}
}

