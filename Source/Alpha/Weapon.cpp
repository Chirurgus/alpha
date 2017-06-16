// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "Weapon.h"

AWeapon::AWeapon()
	: Super {}
{
}

void AWeapon::Use()
{
	UE_LOG(ALog, Log, TEXT("AWeapon is Use()d"));
	return;
}


