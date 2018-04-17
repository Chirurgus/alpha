// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Character/CharacterBase.h"
#include "Include/Item/GunProjectile.h"
#include "Include/Item/GunBase.h"


// Sets default values
AGunBase::AGunBase()
	: Super {}
	, _ProjectileClass {AGunProjectile::StaticClass()}
	, _MuzzleOffset {0,0,0}
	, _FireVector {0, 90, 0}
{
}

void AGunBase::Use()
{
	if (!_ProjectileClass) {
		UE_LOG(ALog, Warning, TEXT("ProjectileClass in AGunBase is null"));
		return;
	}

	auto* player {
		Cast<ACharacterBase>(GetRootComponent()->GetAttachParent()
													->GetAttachmentRootActor())
	};
	if (!player) {
		UE_LOG(ALog, Warning, TEXT("AGUnBase isn't attached to a CharacterBase"));
		return;
	}

	FVector muzzle_pos{};
	FRotator fire_vect{};
	player->GetController()->GetPlayerViewPoint(muzzle_pos, fire_vect);

	UWorld* const world {GetWorld()};
	if (world) {
		FActorSpawnParameters spawn_param;
		spawn_param.Owner = this;
		spawn_param.Instigator = Instigator;
		// spawn the projectile at the muzzle
		AProjectileBase* const projectile
			{world->SpawnActor<AProjectileBase>(_ProjectileClass,
												muzzle_pos,
												fire_vect,
												spawn_param)};
		if (projectile)
		{
			// find launch direction
			projectile->InitVelocity(fire_vect.Vector());
		}
		else {
			UE_LOG(ALog, Warning, TEXT("SpawnActor() returned null"));
		}
	}
	else {
		UE_LOG(ALog, Warning, TEXT("GetWorld() returned null"));
	}
}

