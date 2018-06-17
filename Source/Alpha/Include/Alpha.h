// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#ifndef __ALPHA_H__
#define __ALPHA_H__

#include "Engine.h"

#define PRINT_DEBUG_MESSAGE(x) GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Red, x);

/*  ALog = Alpha Log
	ALog is for general purpose logs
	ALogCritical is for critical erros
	*/

DECLARE_LOG_CATEGORY_EXTERN(ALog, Log, All);

DECLARE_LOG_CATEGORY_EXTERN(ALogCritical, Log, All);

namespace alpha
{
	enum class CustomDepthStencilValue{
		interactable_outline = 255
	};
}//namespace alpha

#endif
