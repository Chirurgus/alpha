// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon.h"
#include "ProjectileBase.h"
#include "GunBase.generated.h"

UCLASS()
class ALPHA_API AGunBase : public AWeapon
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGunBase();


	void Use() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Gun")
	TSubclassOf<AProjectileBase> _ProjectileClass;
	
	UPROPERTY(EditAnywhere, Category = "Gun")
	FVector _MuzzleOffset;	
};
