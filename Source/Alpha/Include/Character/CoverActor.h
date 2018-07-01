// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Include/Character/VisualActor.h"

#include "CoverActor.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API ACoverActor : public AVisualActor
{
	GENERATED_BODY()
	
public:
	ACoverActor();

	void BeginPlay() override;

	// Get the vector along which the player should be able to move
	FVector GetLatteralDirection() const;

protected:
	UPROPERTY()
	UBoxComponent* BoxComponent;
	
private:
	UFUNCTION()
	void OnBoxCompBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnBoxCompEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
