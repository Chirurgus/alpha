// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"

#include "Include/Item/ProjectileBase.h"
#include "Include/Component/ActiveInventoryComponent.h"
#include "Include/Component/InventoryComponent.h"
#include "Include/Component/CoverComponent.h"

#include "CharacterBase.generated.h"

UCLASS(Blueprintable)
class ALPHA_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetMaxWalkSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetMaxSprintSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetMaxCrouchSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool IsJumpPressed() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool IsInCover() const;

	/* Inventory */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryComponent* GetInventoryComponent();
	
		/* Health */
	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetMaxHealh() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	virtual void Die();

	UFUNCTION(BlueprintCallable, Category = "Health")
	float TakeDamage(float damage,
				     const FDamageEvent& dmg_event,
					 AController* dmg_instigator,
					 AActor* dmg_causer) override;

	float TakeDamageTest(float damage);

	/* Animation */
	UFUNCTION(BlueprintCallable, Category = "Animation")
	bool IsAiming() const;

	UFUNCTION(BlueprintCallable, Category = "Animation")
	bool IsShootPressed() const;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cover")
	UCoverComponent* CoverComponent;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UActiveInventoryComponent* _ActiveInventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UInventoryComponent* _InventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float _Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float _MaxSprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float _MaxWalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float _MaxCrouchSpeed;
	
	bool _is_sprinting {false};
	bool _is_aiming {false};
	bool _is_jump_pressed {false};
	bool _is_shoot_pressed {false};
};
