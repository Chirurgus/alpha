// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "ThirdPersonCameraActor.h"

AThirdPersonCameraActor::AThirdPersonCameraActor()
	: Super {}
	, _SpringArmComponent {CreateDefaultSubobject<USpringArmComponent>("Spring arm component")}
{
	RootComponent = _SpringArmComponent;
	GetCameraComponent()->SetupAttachment(_SpringArmComponent);
	_SpringArmComponent->TargetArmLength = 300;
}


