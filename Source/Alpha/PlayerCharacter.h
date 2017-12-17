// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ALPHA_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();

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
	
	UFUNCTION(Category = "Inventory")
	void OnBeginOverlapItem(UPrimitiveComponent* comp,
							AActor * other_actor,
							UPrimitiveComponent* other_comop,
							int32 other_body_index,
							bool from_sweep,
							const FHitResult& sweep_result);
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* _SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* _CameraComponent;


};