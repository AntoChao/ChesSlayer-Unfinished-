// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayGameMode.h"
#include "UObject/ConstructorHelpers.h"

AGameplayGameMode::AGameplayGameMode() {
	
}

void AGameplayGameMode::BeginPlay() {
	Super::BeginPlay();
}

void AGameplayGameMode::loadInstanceAttributes() {
	// initialize the game instance
	Super::loadInstanceAttributes();
	if (gameInstance) {
		gameDifficulty = gameInstance->getCurrentDifficulty();
		unlockedPieces = gameInstance->getUnlockedPieces();
		isGameWon = gameInstance->getIsGameWon();
		totalStage = gameInstance->getStageNum();
		currentStageNum = gameInstance->getCurrentStageNum();
		allStages = gameInstance->getAllStages();
		allPower = gameInstance->getCurrentPowers();
		newUnlockedPieces = gameInstance->getNewUnlockedPieces();
	}

	// initialize all power pieces
	for (UPower* eachPower : allPower) {
		eachPower->initializeArmyPiecesByName();
	}
}

void AGameplayGameMode::updateInstance() {
	// initialize the game instance
	
	if (gameInstance) {
		gameInstance->setCurrentPowers(allPower);
		gameInstance->setStageNum(1);
	}
}

void AGameplayGameMode::finishCurrentStage() {
	startNextStage();
}

void AGameplayGameMode::startNextStage() {

}

// select the mission to enter
void AGameplayGameMode::selectMission() {
	//initializeMission()
}