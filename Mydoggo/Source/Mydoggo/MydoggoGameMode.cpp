// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MydoggoGameMode.h"
#include "MydoggoHUD.h"
#include "MydoggoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMydoggoGameMode::AMydoggoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMydoggoHUD::StaticClass();
}
