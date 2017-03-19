// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AICharacterBase.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "AIGuard.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API AAIGuard : public AAICharacterBase
{
	GENERATED_BODY()

public:	
	AAIGuard(const FObjectInitializer& obj_init);
	
	virtual void OnPerception(TArray<AActor*> perceved_actors);

	//void PossessedBy(AController* cp) override;
	UAIPerceptionComponent* GetPerceptionComponent();
	void SetPerceptionComponent(UAIPerceptionComponent* p);
	UAISenseConfig_Sight* GetSightConfig();
	void SetSightConfig(UAISenseConfig_Sight* p);
private:
	UPROPERTY(EditAnywhere, Category=Perception)
	UAIPerceptionComponent* _PerceptionComp;
	UPROPERTY(EditAnywhere, Category=Perception)
	UAISenseConfig_Sight* _SightConfig;
};
