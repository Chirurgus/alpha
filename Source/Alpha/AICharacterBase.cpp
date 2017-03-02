// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "AICharacterBase.h"


// Sets default values
AAICharacterBase::AAICharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAICharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}