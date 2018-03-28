// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/World/AlphaGameModeBase.h"

AAlphaGameModeBase::AAlphaGameModeBase()
	: Super()
{
}

AAlphaGameModeBase::AAlphaGameModeBase(const FObjectInitializer & obj_init)
	: Super(obj_init) 
{
/*//these are now set from the editor, and use Blueprints derived from c++ classes.
	static ConstructorHelpers::FClassFinder<APawn> 
		PlayerPawnObject(TEXT("Blueprint'/Game/Blueprints/CharacterBase_BP.CharacterBase_BP_C'"));
	if (PlayerPawnObject.Class)
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}
	DefaultPawnClass = ACharacterBase::StaticClass();
	PlayerControllerClass = ATestPlayerController::StaticClass();
 */
}

void AAlphaGameModeBase::StartPlay()
{
	Super::StartPlay();
}
