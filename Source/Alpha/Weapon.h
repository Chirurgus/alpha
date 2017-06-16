// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Equippable.h"
#include "Weapon.generated.h"

/**
 * A base class for all weapons in the game, this is an inteface that all
 * weapon sub-classes should be acessed through.
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
