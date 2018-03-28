// Fill out your copyright notice in the Description page of Project Settings.

#include "Include/Alpha.h"

#include "Include/Component/CameraManager.h"


ACameraManager::ACameraManager()
	: Super {}
{
	UE_LOG(ALog, Log, TEXT("ACameraManager construtor called."));
}

void ACameraManager::UpdateViewTarget(FTViewTarget& out_vt, float d_time)
{	
	APlayerControllerBase* pc {Cast<APlayerControllerBase>(Super::GetOwningPlayerController())};
	if (!pc) {
		Super::UpdateViewTarget(out_vt, d_time);
		return;
	}

	FTViewTarget vt {out_vt};
	FMinimalViewInfo mvi {vt.POV};

	//mvi.Location = pc->_CameraComponent->GetComponentLocation();
	mvi.Rotation = GetOwningPlayerController()->GetControlRotation();
	vt.POV = mvi;

	SetActorLocationAndRotation(vt.POV.Location, vt.POV.Rotation, false);

	out_vt = vt;
}