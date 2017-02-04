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
	static ConstructorHelpers::FClassFinder<APawn> 
		PlayerPawnObject(TEXT("Pawn'/Game/Blueprints/CharacterBase_BP.CharacterBase_BP'"));
	if (PlayerPawnObject.Class)
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}
	DefaultPawnClass = ACharacterBase::StaticClass();
	PlayerControllerClass = ATestPlayerController::StaticClass();
}

void AAlphaGameModeBase::StartPlay()
{
	Super::StartPlay();
}
