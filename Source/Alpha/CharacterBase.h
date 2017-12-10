// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "ProjectileBase.h"
#include "ActiveInventoryComponent.h"
#include "InventoryComponent.h"
#include "CharacterBase.generated.h"

UCLASS(Blueprintable)
class ALPHA_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();
	//ACharacterBase(const FObjectInitializer& obj_init);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/* Movement */
	UFUNCTION()
	virtual void MoveForward(float v);
	UFUNCTION()
	virtual void MoveRight(float v);
	UFUNCTION()
	virtual void LookUp(float v);
	UFUNCTION()
	virtual void LookRight(float v);
	UFUNCTION()
	virtual void JumpPress();
	UFUNCTION()
	virtual void JumpRelease();
	UFUNCTION()
	virtual void ShootPressed();
	UFUNCTION()
	virtual void ShootReleased();
	UFUNCTION()
	virtual void CrouchPressed();
	UFUNCTION()
	virtual void CrouchReleased();
	UFUNCTION()
	virtual void SprintPressed();
	UFUNCTION()
	virtual void SprintReleased();
	UFUNCTION()
	virtual void AimPressed();
	UFUNCTION()
	virtual void AimReleased();
	
	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetMaxSprintSpeed();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool IsJumpPressed();

	/* Inventory */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryComponent* GetInventoryComponent();
	
	UFUNCTION(Category = "Inventory")
	void OnBeginOverlapItem(UPrimitiveComponent* comp,
							AActor * other_actor,
							UPrimitiveComponent* other_comop,
							int32 other_body_index,
							bool from_sweep,
							const FHitResult& sweep_result);

	/* Health */
	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetMaxHealh() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void Die();

	UFUNCTION(BlueprintCallable, Category = "Health")
	float TakeDamage(float damage,
				     const FDamageEvent& dmg_event,
					 AController* dmg_instigator,
					 AActor* dmg_causer) override;

	float TakeDamageTest(float damage);

	/* Animation */
	UFUNCTION(BlueprintCallable, Category = "Animation")
	bool IsAiming() const;




protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UActiveInventoryComponent* _ActiveInventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UInventoryComponent* _InventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float _Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float _MaxSprintSpeed;


 private:
	bool _is_sprinting {false};
	bool _is_aiming {false};
	bool _is_jump_pressed {false};
};
