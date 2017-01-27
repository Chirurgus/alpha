// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class ALPHA_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();
	ACharacterBase(const FObjectInitializer& obj_init);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION()
	void WalkForward(float v);
	UFUNCTION()
	void WalkRight(float v);
	UFUNCTION()
	void LookUp(float v);
	UFUNCTION()
	void LookRight(float v);
	UFUNCTION()
	void JumpPress();
	UFUNCTION()
	void JumpRelease();
	

protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY()
	UCameraComponent* _camera_comp{nullptr};
	
	
};
