// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "AlphaGameModeBase.h"

AAlphaGameModeBase::AAlphaGameModeBase()
	: Super()
{
}

AAlphaGameModeBase::AAlphaGameModeBase(const FObjectInitializer & obj_init)
	: Super(obj_init) 
{
	DefaultPawnClass = AAlphaCharacter::StaticClass();
	PlayerControllerClass = ATestPlayerController::StaticClass();
	
}

void AAlphaGameModeBase::StartPlay()
{
	Super::StartPlay();
}
