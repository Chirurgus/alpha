// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Character/CharacterBase.h"

#include "Include/Character/CoverActor.h"


ACoverActor::ACoverActor()
	: BoxComponent {CreateDefaultSubobject<UBoxComponent>("Box component")}
{
}

void ACoverActor::BeginPlay()
{
	Super::BeginPlay();

	if (BoxComponent) {
		BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ACoverActor::OnBoxCompBeginOverlap);
		BoxComp->OnComponentEndOverlap.AddDynamic(this, &ACoverActor::OnBoxCompEndOverlap);
	}
}

void ACoverActor::OnBoxCompBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (auto* cb {Cast<ACharacterBase>(OtherActor)}) {
		cb->CoverComponent->SetCanTakeCover(true, this);
	}
}

void ACoverActor::OnBoxCompEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (auto* cb {Cast<ACharacterBase>(OtherActor)}) {
		cb->CoverComponent->SetCanTakeCover(false,this);
	}
}
