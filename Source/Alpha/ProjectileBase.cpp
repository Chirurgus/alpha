// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "ProjectileBase.h"


// Sets default values
AProjectileBase::AProjectileBase()
	: Super{}
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

AProjectileBase::AProjectileBase(const FObjectInitializer& obj_init)
	: Super{obj_init}
{
	_SphereComponent = obj_init.CreateDefaultSubobject<USphereComponent>(this, "ShpereComponent");		
 /*
	_SphereComponent->InitSphereRadius(5.0f);
 */
	
	_MovementComponent = obj_init.CreateAbstractDefaultSubobject<UProjectileMovementComponent>(this, "MovementComponent");
	_MovementComponent->SetUpdatedComponent(_SphereComponent);
 /*
	_MovementComponent->InitialSpeed = 100.0f;
	_MovementComponent->MaxSpeed = 20000.0f;
	_MovementComponent->bRotationFollowsVelocity = true;
	_MovementComponent->bShouldBounce = false;
 */

}
// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProjectileBase::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AProjectileBase::InitVelocity(const FVector& dir)
{
	if (_MovementComponent) {
		_MovementComponent->Velocity = _MovementComponent->InitialSpeed * dir;
	}
}
