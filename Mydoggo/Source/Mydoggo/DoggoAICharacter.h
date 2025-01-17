// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "DoggoAICharacter.generated.h"

UCLASS()
class MYDOGGO_API ADoggoAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADoggoAICharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	FVector	GetPOILocation() const;

	UFUNCTION(BlueprintCallable)
	FVector	GetHidePOILocation() const;

	UFUNCTION(BlueprintCallable)
	void SetRandomNextPOI();

	UFUNCTION(BlueprintCallable)
	void SetRandomPOIToHide();

	UFUNCTION(BlueprintCallable)
	class ADoggoPOI* GetPOIToHide() const { return POIToHide; }

	UFUNCTION(BlueprintCallable)
	class ADoggoPOI* GetCurrentPOI() const { return CurrentPOI; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


protected:
	UPROPERTY(EditAnywhere)
	TArray<class ADoggoPOI*> POIList;

private:
	class MydoggoCharcter* CachedPlayer =nullptr;

	class ADoggoPOI* CurrentPOI = nullptr;
	class ADoggoPOI* POIToHide = nullptr;

};
