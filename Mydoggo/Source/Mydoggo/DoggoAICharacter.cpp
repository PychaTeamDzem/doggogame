// Fill out your copyright notice in the Description page of Project Settings.

#include "DoggoAICharacter.h"
#include "DoggoPOI.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
ADoggoAICharacter::ADoggoAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 600.f, 0.f);
}

// Called when the game starts or when spawned
void ADoggoAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoggoAICharacter::SetRandomNextPOI()
{
	if (POIList.Num() <= 0)
	{
		CurrentPOI = nullptr;
		return;
	}
		
	int32 RandomNumber = FMath::RandRange(0, POIList.Num()-1);
	CurrentPOI =  POIList[RandomNumber];
}

void ADoggoAICharacter::SetRandomPOIToHide()
{
	if (POIList.Num() <= 0)
	{
		CurrentPOI = nullptr;
		return;
	}
	TArray<class ADoggoPOI*> POIWithFootprintsList;
	for (ADoggoPOI* poi : POIList)
	{
		if (poi->IsValidLowLevel() && poi->HasFootprints() )
			POIWithFootprintsList.Add(poi);
	}
	
	if (POIWithFootprintsList.Num() <= 0)
		return; 

	int32 RandomNumber = FMath::RandRange(0, POIWithFootprintsList.Num() - 1);
	
	POIToHide = POIWithFootprintsList[RandomNumber];
}


// Called every frame
void ADoggoAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADoggoAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

FVector ADoggoAICharacter::GetPOILocation() const
{
	if(!GetCurrentPOI())
		return FVector(0.f,0.f,0.f);
	return GetCurrentPOI()->GetActorLocation();
}

FVector ADoggoAICharacter::GetHidePOILocation() const
{
	if (!GetPOIToHide())
		return FVector(0.f, 0.f, 0.f);
	return GetPOIToHide()->GetActorLocation();
}

