// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoggoPOI.generated.h"

UCLASS()
class MYDOGGO_API ADoggoPOI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoggoPOI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	void SetFootprintsVisible() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool HasFootprints() const { return bHasFootprints; }

	UFUNCTION(BlueprintCallable)
	void OnHideGameChanged(bool bStarted);
	
protected:
	UPROPERTY(EditAnywhere)
	TArray<class ADoggoFootprints*> FootprintList;

	UPROPERTY(EditAnywhere)
	bool bHasFootprints = false;

private:
	bool bHideGameStarted = false;

};
