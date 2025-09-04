// Copyright Epic Games, Inc. All Rights Reserved.

#include "Game_C_01GameMode.h"
#include "Game_C_01Character.h"
#include "UObject/ConstructorHelpers.h"

AGame_C_01GameMode::AGame_C_01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
