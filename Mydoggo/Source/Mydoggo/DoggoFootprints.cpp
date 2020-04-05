// Fill out your copyright notice in the Description page of Project Settings.
#include "DoggoFootprints.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADoggoFootprints::ADoggoFootprints()
{
	SetActorRotation(FRotator(-180, 0, 0));
}

void ADoggoFootprints::BeginPlay()
{
	SetActorRotation(FRotator(-180, 0, 0));
}

void ADoggoFootprints::ChangeVisibility(bool NewVisibility)
{
	float PitchRotation = -180;
	if (NewVisibility)
		PitchRotation = 0;
	
	SetActorRotation(FRotator(PitchRotation,0,0));
}
