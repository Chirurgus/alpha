// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Item/GunProjectile.h"


// Sets default values
AGunProjectile::AGunProjectile()
	: Super{}
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	GetColisionComponent()->OnComponentBeginOverlap.AddDynamic(this, &AGunProjectile::OnOverlap);
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

void AGunProjectile::OnOverlap(UPrimitiveComponent * OverlappedComponent,AActor * OtherActor,UPrimitiveComponent * OtherComp,int32 OtherBodyIndex,bool bFromSweep,const FHitResult & SweepResult)
{
	PRINT_DEBUG_MESSAGE("I'm overlaping!!!");
	ACharacterBase* cp {Cast<ACharacterBase>(OtherActor)};	
	if (cp) {
		cp->TakeDamageTest(100);
	}	
}

