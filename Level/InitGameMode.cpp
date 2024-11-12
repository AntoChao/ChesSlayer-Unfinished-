// Copyright Epic Games, Inc. All Rights Reserved.

#include "InitGameMode.h"
#include "UObject/ConstructorHelpers.h"

AInitGameMode::AInitGameMode() {
	
}

void AInitGameMode::BeginPlay() {
	Super::BeginPlay();
}

void AInitGameMode::loadInstanceAttributes() {
	Super::loadInstanceAttributes();
	// initialize the game instance
	if (gameInstance) {
		isFirstTimeOpening = gameInstance->getIsFirstTimeOpening();
		isLastGameFinished = gameInstance->getIsLastGameFinished();
	}
}

bool AInitGameMode::getIfIsFirstTimeOpening() {
	return isFirstTimeOpening;
}

bool AInitGameMode::getIfIsLastGameFinished() {
	return isLastGameFinished;
}