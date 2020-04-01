// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DoggoAIController.generated.h"

/**
 * 
 */
UCLASS()
class MYDOGGO_API ADoggoAIController : public AAIController
{
	GENERATED_BODY()

public:
	ADoggoAIController();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnPossess(APawn* DogPawn) override;

	virtual FRotator GetControlRotation() const override;

	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*>& DetectedPawns);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "View")
		float AISightRadius = 2000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "View")
		float AISightAge = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "View")
		float AILoseSightRadius = 2500.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "View")
		float AIFieldOfView = 90.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "View")
		class UAISenseConfig_Sight* Sight_Config;
};

