// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Weapon.h"
#include "ActiveInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UActiveInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActiveInventoryComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime,
							   ELevelTick TickType,
							   FActorComponentTickFunction*
							   ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	AWeapon* GetEquippedWeapon();

	/* Tries to equip a weapon, returns true iff the weapon w was successfuly equipped */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool EquipWeapon(AWeapon* w);

	/* Checks if weapon w can be equipped */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool CanEquipWeapon(AWeapon* w);

private:

	UPROPERTY()
	AWeapon* _Weapon;
	
};
