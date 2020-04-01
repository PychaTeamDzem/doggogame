// Fill out your copyright notice in the Description page of Project Settings.


#include "DoggoAIController.h"


#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ADoggoAIController::ADoggoAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	Sight_Config = CreateDefaultSubobject<UAISenseConfig_Sight>(L"Sight Config");
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(L"Perception Component"));

	Sight_Config->SightRadius = AISightRadius;
	Sight_Config->LoseSightRadius = AILoseSightRadius;
	Sight_Config->PeripheralVisionAngleDegrees = AIFieldOfView;
	Sight_Config->SetMaxAge(AISightAge);

	Sight_Config->DetectionByAffiliation.bDetectEnemies = true;
	Sight_Config->DetectionByAffiliation.bDetectFriendlies = true;
	Sight_Config->DetectionByAffiliation.bDetectNeutrals = false;

	if ensure(!GetPerceptionComponent()) { return; }
	GetPerceptionComponent()->SetDominantSense(*Sight_Config->GetSenseImplementation());

	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ADoggoAIController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*Sight_Config);
}

void ADoggoAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ADoggoAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ADoggoAIController::OnPossess(APawn* DogPawn)
{
	Super::OnPossess(DogPawn);
}

FRotator ADoggoAIController::GetControlRotation() const
{
	if (!GetPawn())
		return FRotator(0.f, 0.f, 0.f);

	return FRotator(0.f, GetPawn()->GetActorRotation().Yaw, 0.f);
}

void ADoggoAIController::OnPawnDetected(const  TArray<AActor*>& DetectedPawns)
{
	if (DetectedPawns.Num() <= 0)
		return;
}
