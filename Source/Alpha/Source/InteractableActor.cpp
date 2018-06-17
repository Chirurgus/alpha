// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Character/InteractableActor.h"


AInteractableActor::AInteractableActor()
{
	GetActorMesh()->SetCustomDepthStencilValue(
		static_cast<int>(alpha::CustomDepthStencilValue::interactable_outline)
	);
}

void AInteractableActor::OnFocus()
{
	GetActorMesh()->SetRenderCustomDepth(true);
}

void AInteractableActor::OnEndFocus()
{
	GetActorMesh()->SetRenderCustomDepth(false);
}
