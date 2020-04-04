// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MydoggoCharacter.generated.h"

class UInputComponent;

UCLASS(config=Game)
class AMydoggoCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

public:
	AMydoggoCharacter();

protected:
	virtual void BeginPlay();

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;


	/** Affinity with the doge. */
private:
		
		float MaxAfiinity = 100;

		UPROPERTY(EditAnywhere)
		float DogeAffinity = 0;

		int DogeBones = 0;

protected:

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	void SetDoggoCharacter();
public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	UFUNCTION(BlueprintCallable, Category = "Dog")
	float	GetDogeAffinity() const;

	UFUNCTION(BlueprintCallable, Category = "Dog")
	void	SetDogeAffinity(float AddAffinity);
	
	UFUNCTION(BlueprintCallable, Category = "Bones")
	int		GetDogeBones() const;

	UFUNCTION(BlueprintCallable, Category = "Bones")
	void	SetDogeBones(int AddBones);

	UFUNCTION(BlueprintCallable)
	float	GetMaxAffinity() const { return MaxAfiinity; }

	UFUNCTION(BlueprintCallable)
	class ADoggoAICharacter* GetCachedDoggo() const { return CachedDoggo; }

	UFUNCTION(BlueprintCallable)
	bool IsHideGameStarted() const { return bHideGameStarted; }

	UFUNCTION(BlueprintCallable)
	void SetHideGameChanged(bool bNewHideChange);

private:
	class ADoggoAICharacter* CachedDoggo = nullptr;

	bool bHideGameStarted = false;
	bool bWashGameStarted = false;
	bool bLearnGameStarted = false;
};

