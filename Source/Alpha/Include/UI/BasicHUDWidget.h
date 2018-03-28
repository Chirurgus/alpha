// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WidgetBase.h"
#include "BasicHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class ALPHA_API UBasicHUDWidget : public UWidgetBase
{
	GENERATED_BODY()
	
public:
	UBasicHUDWidget(const FObjectInitializer& obj_init);

	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetPlayerHealth() const;
	
};
