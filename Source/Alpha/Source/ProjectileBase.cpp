// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Item/ProjectileBase.h"


// Sets default values
AProjectileBase::AProjectileBase()
	: Super{}
	, _LifeDuration {3}
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_SphereComponent
		= CreateDefaultSubobject<USphereComponent>("ShpereComponent");		
	/*
	_SphereComponent->InitSphereRadius(5.0f);
	*/
	RootComponent = _SphereComponent;
	
	_MovementComponent
		= CreateDefaultSubobject<UProjectileMovementComponent> ("MovementComponent");
	_MovementComponent->SetUpdatedComponent(_SphereComponent);
	_MovementComponent->InitialSpeed = 500.0f;
	/*
	_MovementComponent->MaxSpeed = 20000.0f;
	_MovementComponent->bRotationFollowsVelocity = true;
	_MovementComponent->bShouldBounce = false;
	*/
}

// Called when the game starts or when spawned
void AProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	auto* world {GetWorld()};
	world->GetTimerManager().SetTimer(_DeathTimer,
									  [world, this]() { if (world) world->DestroyActor(this); },
									  _LifeDuration,
									  false,
									  _LifeDuration
	);
}

void AProjectileBase::EndPlay(const EEndPlayReason::Type reason)
{
	Super::EndPlay(reason);

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
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
