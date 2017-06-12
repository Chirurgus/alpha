// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Equippable.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API AWeapon : public AEquippable
{
	GENERATED_BODY()
	
public:
	AWeapon();

protected:
	virtual void Use();
	
};
