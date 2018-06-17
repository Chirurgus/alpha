// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "VisualActor.generated.h"
/*
 * Base class for anything that may need a visual representation in the world.
 */
UCLASS()
class ALPHA_API AVisualActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVisualActor();

protected:
	UFUNCTION(BlueprintCallable, Category = "Mesh")
	UStaticMeshComponent* GetActorMesh() const;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UArrowComponent* _ArrowComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* _Mesh;
};
