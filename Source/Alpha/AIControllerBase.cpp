// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "AIControllerBase.h"


AAIControllerBase::AAIControllerBase(const FObjectInitializer& obj_init)
	: Super{obj_init}
{
	_BlackboardComp =
		obj_init.CreateDefaultSubobject<UBlackboardComponent>
						(this, "BlackboardComponent");
	_BehaviorTreeComp = obj_init.CreateDefaultSubobject<UBehaviorTreeComponent>
						(this, "BehaviorTreeComponent");
}

void AAIControllerBase::Possess(APawn* puppet)
{
	if (puppet) {
		Super::Possess(puppet);
		
	}
}

inline UBlackboardComponent* AAIControllerBase::GetBlackboardComponent()
{
	return _BlackboardComp;
}

inline UBehaviorTreeComponent* AAIControllerBase::GetBehaviorTreeComponent()
{
	return _BehaviorTreeComp;
}


