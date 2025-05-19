// Copyright Epic Games, Inc. All Rights Reserved.

#include "Prototype1_FPSGameMode.h"
#include "Prototype1_FPSCharacter.h"
#include "UObject/ConstructorHelpers.h"

APrototype1_FPSGameMode::APrototype1_FPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
