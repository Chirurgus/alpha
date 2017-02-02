// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "AlphaCharacter.h"
#include "CharacterBase.h"
#include "TestPlayerController.h"
#include "AlphaGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API AAlphaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AAlphaGameModeBase();
	AAlphaGameModeBase(const FObjectInitializer& obj_init);

	void StartPlay() override;
};
