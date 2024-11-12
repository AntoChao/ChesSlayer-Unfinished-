// Copyright Epic Games, Inc. All Rights Reserved.

#include "PostgameGameMode.h"
#include "UObject/ConstructorHelpers.h"

APostgameGameMode::APostgameGameMode()
{
	
}

void APostgameGameMode::BeginPlay() {
	Super::BeginPlay();
}

void APostgameGameMode::loadInstanceAttributes() {
	// initialize the game instance
	Super::loadInstanceAttributes();
	if (gameInstance) {
		currentDifficulty = gameInstance->getCurrentDifficulty();
		unlockedPieces = gameInstance->getUnlockedPieces();
		isGameWon = gameInstance->getIsGameWon();
		totalStageNum = gameInstance->getStageNum();
		currentStage = gameInstance->getCurrentStageNum();
		allStages = gameInstance->getAllStages();
		currentAllPowers = gameInstance->getCurrentPowers();
		currentEnemiesKilledCount = gameInstance->getTotalEnemiesKilled();
		newUnlockedPieces = gameInstance->getNewUnlockedPieces();
	}
}

void APostgameGameMode::updateInstance() {
	// initialize the game instance
	if (gameInstance) {
		return;
	}
}