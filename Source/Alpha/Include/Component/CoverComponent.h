// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Include/Character/CoverActor.h"

#include "CoverComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALPHA_API UCoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCoverComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Cover")
	bool GetCanTakeCover() const;

	UFUNCTION(BlueprintCallable, Category = "Cover")
	bool IsInCover() const;

	UFUNCTION(BlueprintCallable, Category = "Cover")
	FVector GetCoverMovementDirection() const;

	UFUNCTION(BlueprintCallable, Category = "Cover")
	void SetCanTakeCover(const bool b, ACoverActor* cover);

	UFUNCTION(BlueprintCallable, Category = "Cover")
	void SetInCover(const bool b);


protected:
	void BeginPlay() override;
	
private:
	ACoverActor * Cover;

	UPROPERTY()
	FVector CoverMovementDirection;
	
	UPROPERTY()
	bool bCanTakeCover;

	UPROPERTY()
	bool bInCover;

};
