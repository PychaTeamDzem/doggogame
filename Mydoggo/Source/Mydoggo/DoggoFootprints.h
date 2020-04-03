// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoggoFootprints.generated.h"

UCLASS()
class MYDOGGO_API ADoggoFootprints : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoggoFootprints();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void ChangeVisibility(bool NewVisibility);

};
