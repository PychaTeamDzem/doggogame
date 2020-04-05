// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deliver_trigger.generated.h"

UCLASS()
class MYDOGGO_API ADeliver_trigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeliver_trigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	TArray<class ADeliveryObject*> GetObjectTimeList() { return ObjectTimeList; }

protected:

	UPROPERTY(EditAnywhere)
	TArray<class ADeliveryObject*> ObjectTimeList;

};
