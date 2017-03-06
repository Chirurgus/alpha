// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "AICharacterBase.generated.h"

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
	
private:
	UPROPERTY(EditAnywhere, Category=Perception)
	class UAIPerceptionComponent* _PerceptionComp;
};
