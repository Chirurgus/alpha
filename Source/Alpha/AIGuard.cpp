// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "AIGuard.h"
#include "AIControllerBase.h"

AAIGuard::AAIGuard(const FObjectInitializer& obj_init)
	: Super{obj_init}
{
	_SightConfig = obj_init.CreateDefaultSubobject<UAISenseConfig_Sight>
							(this, "SightConfig");
	if (_PerceptionComp && _SightConfig) {
		_SightConfig->SightRadius = 3000;
		_SightConfig->LoseSightRadius = 3200;
		_SightConfig->PeripheralVisionAngleDegrees = 90;
		_SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		_SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		_SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	}
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

UAIPerceptionComponent* AAIGuard::GetPerceptionComponent()
{
	return _PerceptionComp;
}

void AAIGuard::SetPerceptionComponent(UAIPerceptionComponent* p)
{
	_PerceptionComp = p;
}

UAISenseConfig_Sight* AAIGuard::GetSightConfig()
{
	return _SightConfig;
}

void AAIGuard::SetSightConfig(UAISenseConfig_Sight* p)
{
	_SightConfig = p;
}

