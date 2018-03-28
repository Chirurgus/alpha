// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "WidgetBase.generated.h"

/**
 * Base class for widgets.
 * Widgets are to be created, and their interface exposed in C++,
 * then extended and designed in blueprint, using the exposed C++
 * interface.
 */
UCLASS()
class ALPHA_API UWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UWidgetBase(const FObjectInitializer& obj_init);

};
