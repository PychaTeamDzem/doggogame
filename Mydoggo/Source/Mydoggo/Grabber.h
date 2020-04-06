// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYDOGGO_API UGrabber : public UActorComponent
{
	GENERATED_BODY()


public:
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 500.f;
	class UPhysicsHandleComponent* PhysicsHandle = nullptr;
	class UInputComponent* InputComponent = nullptr;
	void FindPhysicsComponent();
	void SetupInputComponent();
	//Return hit for 1st physics body in reach
	FHitResult GetFirstPhysicsBodyInReach();
	void Grab();
	void Release();
	FVector GetReachLineStart();
	FVector GetReachLineEnd();
};
