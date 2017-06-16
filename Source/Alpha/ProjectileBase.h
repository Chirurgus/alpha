// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProjectileBase.generated.h"

UCLASS(Blueprintable)
class ALPHA_API AProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	virtual void InitVelocity(const FVector& dir);

	virtual USphereComponent* GetColisionComponent() { return _SphereComponent; }

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USphereComponent* _SphereComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UProjectileMovementComponent* _MovementComponent;
};
