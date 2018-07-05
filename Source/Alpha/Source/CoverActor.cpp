// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Character/CharacterBase.h"

#include "Include/Character/CoverActor.h"


ACoverActor::ACoverActor()
	: BoxComponent {CreateDefaultSubobject<UBoxComponent>("Box component")}
{
	BoxComponent->AttachToComponent(RootComponent,
							 FAttachmentTransformRules {
								EAttachmentRule::KeepRelative,
								EAttachmentRule::KeepRelative,
								EAttachmentRule::KeepRelative,
								false
							}
	);
}

void ACoverActor::BeginPlay()
{
	Super::BeginPlay();

	if (BoxComponent) {
		BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoverActor::OnBoxCompBeginOverlap);
		BoxComponent->OnComponentEndOverlap.AddDynamic(this, &ACoverActor::OnBoxCompEndOverlap);
	}
}

FVector ACoverActor::GetLatteralDirection() const
{
	FRotator rot {_ArrowComponent->GetComponentRotation()};
	return (rot + FRotator{0,90,0}).Vector();
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
