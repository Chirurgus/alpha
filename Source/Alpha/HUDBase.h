// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "WidgetBase.h"
#include "HUDBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ALPHA_API AHUDBase : public AHUD
{
	GENERATED_BODY()
	
public:

	AHUDBase();
	
	void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UWidgetBase> WidgetBaseClass;
	
private:

	UWidgetBase* _WidgetBase = nullptr; 
		
};
