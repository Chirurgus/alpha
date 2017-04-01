// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "AIControllerBase.h"
#include "AIGuard.h"


AAIControllerBase::AAIControllerBase(const FObjectInitializer& obj_init)
	: Super{obj_init}
{
	_BehaviorTreeComp = obj_init.CreateDefaultSubobject<UBehaviorTreeComponent>
						(this, "BehaviorTreeComponent");
	  /* Both blackboard and Perception components from AIController (base class)
		* need to be initialized since they are null to begin with. 
		*/
	Blackboard = obj_init.CreateDefaultSubobject<UBlackboardComponent>
						(this, "BlackboardComponent");
}

void AAIControllerBase::Possess(APawn* puppet)
{
	if (!GetBlackboardComponent() || !GetPerceptionComponent()) {
		return;
	}
	if (puppet) {
		Super::Possess(puppet);
		AAIGuard* gp {Cast<AAIGuard>(puppet)};
		if (gp && gp->GetBehaviorTreeComponent()) {
   /*
			GetBlackboardComponent()->
				InitializeBlackboard(*(gp->GetBehaviorTreeComponent()->GetBlackboardComponent()->GetBlackboardAsset()));//blackboard component in behavior tree is null
	*/
		}	
	}
}

inline UBlackboardComponent* AAIControllerBase::GetBlackboardComponent()
{
	return Blackboard;
}

inline UBehaviorTreeComponent* AAIControllerBase::GetBehaviorTreeComponent()
{
	return _BehaviorTreeComp;
}

inline void AAIControllerBase::SetBehaviorTreeComponent(UBehaviorTreeComponent* p)
{
	_BehaviorTreeComp = p;
}