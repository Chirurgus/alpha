// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICharacterBase.generated.h"

//Forward declarations
//class UAIPerceptionComponent;

UCLASS()
class ALPHA_API AAICharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAICharacterBase();

	AAICharacterBase(const FObjectInitializer& obj_init);

	UBehaviorTreeComponent* GetBehaviorTreeComponent();

private:
	UPROPERTY(VisibleAnywhere, Category=Behavior)
	UBehaviorTreeComponent* _BehaviorTreeComp;

};
