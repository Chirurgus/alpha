// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GunProjectile.generated.h"

UCLASS(Blueprintable)
class ALPHA_API AGunProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunProjectile();
	AGunProjectile(const FObjectInitializer& obj_init);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	void InitVelocity(const FVector& dir);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USphereComponent* _SphereComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* _MovementComponent;
};
