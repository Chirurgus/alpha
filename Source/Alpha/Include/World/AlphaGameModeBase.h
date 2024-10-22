// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"

#include "Include/Character/CharacterBase.h"
#include "Include/Character/PlayerControllerBase.h"
#include "AlphaGameModeBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ALPHA_API AAlphaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AAlphaGameModeBase();
	AAlphaGameModeBase(const FObjectInitializer& obj_init);

	void StartPlay() override;
};
