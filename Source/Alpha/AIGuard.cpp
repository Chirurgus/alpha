// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "AIGuard.h"

AAIGuard::AAIGuard(const FObjectInitializer& obj_init)
	: Super{obj_init}
{
	_PerceptionComp = obj_init.CreateDefaultSubobject<UAIPerceptionComponent>
							(this, "PerceptionComponent");
	_SightConfig = obj_init.CreateDefaultSubobject<UAISenseConfig_Sight>
							(this, "SightConfig");
	if (_PerceptionComp && _SightConfig) {
		_SightConfig->SightRadius = 100;
		_SightConfig->LoseSightRadius = 120;
		_SightConfig->PeripheralVisionAngleDegrees = 360;
		_SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		_SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		_SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		_PerceptionComp->ConfigureSense(*_SightConfig);
		_PerceptionComp->
			SetDominantSense(_SightConfig->GetSenseImplementation());
		_PerceptionComp->OnPerceptionUpdated.AddDynamic(this, &AAIGuard::OnPerception);
	
	}
}

void AAIGuard::OnPerception(TArray<AActor*> perceved_actors)
{
	PRINT_DEBUG_MESSAGE("HE SEES YOU...");
}

