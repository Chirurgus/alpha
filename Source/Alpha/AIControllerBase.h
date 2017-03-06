// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "AIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()
public:
	AAIControllerBase(const FObjectInitializer& obj_init);
	
	void Possess(APawn* puppet) override;
	
private:
	UBlackboardComponent* _BlackboardComp;
	UBehaviorTreeComponent* _BehaviorTreeComp;	
};
