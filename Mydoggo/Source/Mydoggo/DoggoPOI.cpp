// Fill out your copyright notice in the Description page of Project Settings.


#include "DoggoPOI.h"
#include "DoggoFootprints.h"

// Sets default values
ADoggoPOI::ADoggoPOI()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoggoPOI::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoggoPOI::OnHideGameChanged(bool bStarted)
{
	bHideGameStarted = bStarted;
	SetFootprintsVisible();
}

void ADoggoPOI::SetFootprintsVisible() const
{
	for (ADoggoFootprints* doggoFootprint : FootprintList) 
	{
		if (!doggoFootprint)
			continue;
		doggoFootprint->ChangeVisibility(bHideGameStarted);
	}
}

// Called every frame
void ADoggoPOI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

