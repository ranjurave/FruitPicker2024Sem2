// Copyright Epic Games, Inc. All Rights Reserved.

#include "FruitPickerGameMode.h"
#include "FruitPickerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFruitPickerGameMode::AFruitPickerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
