// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "ActiveInventoryComponent.h"


// Sets default values for this component's properties
UActiveInventoryComponent::UActiveInventoryComponent()
	: Super {},
	_Weapon {nullptr}
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UActiveInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActiveInventoryComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

}

AWeapon* UActiveInventoryComponent::GetEquippedWeapon()
{
	return _Weapon;
}

bool UActiveInventoryComponent::EquipWeapon(AWeapon* w)
{
	UE_LOG(ALog, Log, TEXT("Trying to equip a weapon."));
	if (!CanEquipWeapon(w)) {
		UE_LOG(ALog, Log, TEXT("Weapon can't be equipped."));
		return false;
	}
	UE_LOG(ALog, Log, TEXT("Weapon was equipped."));
	w->Equip(GetOwner());
	_Weapon = w;
	return true;
}

bool UActiveInventoryComponent::CanEquipWeapon(AWeapon * w)
{
	return w != nullptr && w->CanEquip(GetOwner());
}

