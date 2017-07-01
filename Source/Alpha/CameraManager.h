// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/PlayerCameraManager.h"
#include "PlayerControllerBase.h"
#include "CameraManager.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API ACameraManager : public APlayerCameraManager
{
	GENERATED_BODY()
	
public:
	ACameraManager();
	
	void UpdateViewTarget(FTViewTarget& out_vt, float d_time) override;
};
