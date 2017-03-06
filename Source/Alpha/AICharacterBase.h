// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
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

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UAIPerceptionComponent* GetPerceptionComponent();

private:
	UPROPERTY(EditAnywhere, Category=Perception)
	UAIPerceptionComponent* _PerceptionComp;
};
