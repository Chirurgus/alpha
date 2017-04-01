// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "AIGuard.h"
#include "AIControllerBase.h"

AAIGuard::AAIGuard(const FObjectInitializer& obj_init)
	: Super{obj_init}
{
	
}

void AAIGuard::OnPerception(TArray<AActor*> perceved_actors)
{
	PRINT_DEBUG_MESSAGE("HE SEES YOU...");
}

/*
void AAIGuard::PossessedBy(AController* cp)
{
	Super::PossessedBy(cp);
	AAIControllerBase* p {Cast<AAIControllerBase>(cp)};	
	if (p) {
		_PerceptionComp = p->GetPerceptionComponent();
	}
}
*/