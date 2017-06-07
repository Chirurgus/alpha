// Fill out your copyright notice in the Description page of Project Settings.

#include "Alpha.h"
#include "VisualActor.h"


// Sets default values
AVisualActor::AVisualActor()
	: Super {},
	_Mesh {CreateDefaultSubobject<UStaticMeshComponent>("Mesh Component")}
{
	
}