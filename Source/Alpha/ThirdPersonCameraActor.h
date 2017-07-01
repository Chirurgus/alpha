// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraActor.h"
#include "ThirdPersonCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API AThirdPersonCameraActor : public ACameraActor
{
	GENERATED_BODY()
	
public:
	AThirdPersonCameraActor();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* _SpringArmComponent;
};
