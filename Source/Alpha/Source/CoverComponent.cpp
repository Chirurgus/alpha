// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Component/CoverComponent.h"


// Sets default values for this component's properties
UCoverComponent::UCoverComponent()
	: bCanTakeCover{false}
	, bInCover{false}
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCoverComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UCoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UCoverComponent::GetCanTakeCover() const
{
	return bCanTakeCover;
}

bool UCoverComponent::IsInCover() const
{
	return bInCover;
}

FVector UCoverComponent::GetCoverMovementDirection() const
{
	return CoverMovementDirection;
}

void UCoverComponent::SetCanTakeCover(const bool b, ACoverActor* cover)
{
	if (cover && b) {
		bCanTakeCover = true;

		CoverMovementDirection = cover->GetLatteralDirection();
	}
	else {
		bCanTakeCover = false;
	}
}

void UCoverComponent::SetInCover(const bool b)
{
	bInCover = b;
}

