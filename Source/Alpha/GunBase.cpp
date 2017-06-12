// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "GunBase.h"


// Sets default values
AGunBase::AGunBase()
	: Super {}
{
	/* Default projectile class */
	_ProjectileClass = AProjectileBase::StaticClass();
	_MuzzleOffset = FVector {0,0,0};
}

void AGunBase::Use()
{
	if (!_ProjectileClass) {
		return;
	}

	FVector camera_pos {GetActorLocation()};
	FRotator camera_rot {GetActorRotation()};
	//GetActorEyesViewPoint(camera_pos, camera_rot);
	const FRotator muzzle_rot {camera_rot};
	const FVector muzzle_pos {camera_pos
		+ FTransform(camera_rot).TransformVector(_MuzzleOffset)};
	UWorld* const world {GetWorld()};
	if (world) {
		FActorSpawnParameters spawn_param;
		spawn_param.Owner = this;
		spawn_param.Instigator = Instigator;
		// spawn the projectile at the muzzle
		AProjectileBase* const projectile
			{world->SpawnActor<AProjectileBase>(_ProjectileClass,
												muzzle_pos,
												muzzle_rot,
												spawn_param)};
		if (projectile)
		{
			// find launch direction
			projectile->InitVelocity(muzzle_rot.Vector());
		}
	}
}

