// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
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

	UFUNCTION(BlueprintCallable, Category = "AI")
	UBlackboardComponent* GetBlackboardComponent();

	UFUNCTION(BlueprintCallable, Category = "AI")
	UBehaviorTreeComponent* GetBehaviorTreeComponent();

	UFUNCTION(BlueprintCallable, Category = "AI")
	void SetBehaviorTreeComponent(UBehaviorTreeComponent* p);

private:
	UPROPERTY(EditAnywhere, Category="Perception")
	UBehaviorTreeComponent* _BehaviorTreeComp;	

};
