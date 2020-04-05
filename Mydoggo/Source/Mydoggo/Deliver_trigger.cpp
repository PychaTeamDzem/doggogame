// Fill out your copyright notice in the Description page of Project Settings.


#include "Deliver_trigger.h"

// Sets default values
ADeliver_trigger::ADeliver_trigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeliver_trigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADeliver_trigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

