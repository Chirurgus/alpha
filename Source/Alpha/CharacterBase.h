// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "ProjectileBase.h"
#include "ActiveInventoryComponent.h"
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
	
	
	UFUNCTION(BlueprintCallable, Category = "Health")
	void Die();

	UFUNCTION(BlueprintCallable, Category = "Health")
	float TakeDamage(float damage,
				     const FDamageEvent& dmg_event,
					 AController* dmg_instigator,
					 AActor* dmg_causer) override;
	float TakeDamageTest(float damage);

	UFUNCTION(Category = "Inventory")
	void OnBeginOverlapItem(AActor* MyOverlappedActor, AActor* OtherActor);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* _CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* _CameraBoonComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UActiveInventoryComponent* _ActiveInventoryComponent;

	/*
	UPROPERTY(EditAnywhere, Category = "Projectile")
	TSubclassOf<AProjectileBase> _ProjectileClass;
	
	UPROPERTY(EditAnywhere, Category = "Gameplay")
	FVector _MuzzleOffset;
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float _Health;


 private:
	bool _is_sprinting{false};
};
