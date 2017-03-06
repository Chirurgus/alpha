// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "AICharacterBase.h"

// Sets default values
AAICharacterBase::AAICharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AAICharacterBase::AAICharacterBase(const FObjectInitializer& obj_init)
	: Super {obj_init}
{
	_PerceptionComp = obj_init.CreateDefaultSubobject<UAIPerceptionComponent>
									(this, "PerceptionComponent");
}
// Called when the game starts or when spawned
void AAICharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

inline UAIPerceptionComponent* AAICharacterBase::GetPerceptionComponent()
{
	return _PerceptionComp;
}