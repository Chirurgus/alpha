// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"

#include "WidgetBase.h"
#include "HUDBase.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EUiCategory : uint8 {
	HUD,
	PauseMenu,
	EscMenu
};

UCLASS(Blueprintable)
class ALPHA_API AHUDBase : public AHUD
{
	GENERATED_BODY()
	
public:

	AHUDBase();
	
	/* Display UI of a given category to the player */
	UFUNCTION(BlueprintCallable, Category =  "UI")
	bool ShowUi(EUiCategory category);
	
	/* Remove UI of a given category form the player screen */
	UFUNCTION(BlueprintCallable, Category =  "UI")
	bool HideUi(EUiCategory category);

	/* Add a Widget to the category, does not show or hide the category iteslf */
	UFUNCTION(BlueprintCallable, Category =  "UI")
	bool AddToCategory(EUiCategory category, FName registered_widget_type);

	/* Remove a Widget from the catgeoyr, does not show or hide the catogory itself */
	UFUNCTION(BlueprintCallable, Category = "UI")
	bool RemoveFromCategory(EUiCategory category, FName registered_widget_type);

	UFUNCTION(BlueprintCallable, Category = "UI")
	bool IsWidgetInCategory(EUiCategory category, FName registered_widget_type);

	/* Remove the last Widget added to the category*/
	UFUNCTION(BlueprintCallable, Category = "UI")
	bool RemoveLastFromCategory(EUiCategory category);
	
	UFUNCTION(BlueprintCallable, Category = "UI")
	void RegisterWidgetClass(FName class_name, UClass* to_register);

	UFUNCTION(BlueprintCallable, Category = "UI")
	TSubclassOf<UWidgetBase> GetRegisteredWidgetClass(FName registered_class);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void UnRegisterWidgetClass(FName registered_class);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	TMap<FName, TSubclassOf<UWidgetBase>> RegisteredWidgetClasses;

private:
	TArray<UWidgetBase*>& getWidgetArray(EUiCategory category);

	UPROPERTY()
	TArray<UWidgetBase*> _HUDWidgets;

	UPROPERTY()
	TArray<UWidgetBase*> _PauseMenuWidgets;

	UPROPERTY()
	TArray<UWidgetBase*> _EscMenuWidgets;
};
