// Copyright Epic Games, Inc. All Rights Reserved.

#include "StartGameMode.h"
#include "UObject/ConstructorHelpers.h"

AStartGameMode::AStartGameMode() {

}

void AStartGameMode::BeginPlay() {
	Super::BeginPlay();
}

void AStartGameMode::loadInstanceAttributes() {
	Super::loadInstanceAttributes();
	if (gameInstance) {
		gameDifficulty = gameInstance->getCurrentDifficulty();
		startStageNum = gameInstance->getStageNum();
		unlockedPieces = gameInstance->getUnlockedPieces();

		for (APiece* eachUnlockedPiece : unlockedPieces) {
			if (eachUnlockedPiece) {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("startGame unlocked piece valid"));
			}
			else {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("startGame unlocked piece NOT valid"));
			}
			
		}
	}
}

void AStartGameMode::AStartGameMode::updateInstance(){
	// initialize the game instance
	if (gameInstance) {
		gameInstance->setCurrentDifficulty(gameDifficulty);
		gameInstance->setCurrentPowers(allPower);
		gameInstance->setStageNum(startStageNum);
		gameInstance->setAllStages(allStages);
	}
}


// Should be called in the last moment
void AStartGameMode::CreateAllPowers() {
	UPower* playerPower = NewObject<UPower>(this, playerPowerClass);
	UPower* empirePower = NewObject<UPower>(this, empirePowerClass);
	UPower* banditPower = NewObject<UPower>(this, banditPowerClass);
	UPower* foreigerPower = NewObject<UPower>(this, foreigerPowerClass);

	playerPower->InitPower(gameDifficulty, 1, selectedPieces);
	empirePower->InitPower(gameDifficulty, 1, selectedPieces);
	banditPower->InitPower(gameDifficulty, 1, selectedPieces);
	foreigerPower->InitPower(gameDifficulty, 1, selectedPieces);

	playerPower->saveArmyPiecesInName();
	empirePower->saveArmyPiecesInName();
	banditPower->saveArmyPiecesInName();
	foreigerPower->saveArmyPiecesInName();

	allPower.Add(playerPower);
	allPower.Add(empirePower);
	allPower.Add(banditPower);
	allPower.Add(foreigerPower);
}

void AStartGameMode::CreateAllStages() {
	for (int i = 0; i < 3; i++) {
		UCSStage* aStage = NewObject<UCSStage>(this, stageClass);
		aStage->loadMapGenerationParameters(gameDifficulty, startStageNum);
		allStages.Add(aStage);
	}
}

void AStartGameMode::InitStage(int aStageNum) {
	if (aStageNum < allStages.Num()) {
		currentStage = allStages[aStageNum];
		currentStage->generateMap();
	}
}


void AStartGameMode::setGameDifficulty(int difficulty) {
	gameDifficulty = difficulty;
}
int AStartGameMode::getGameDifficulty() {
	return gameDifficulty;
}

void AStartGameMode::setInitMaxEnergy(int maxEnergy) {
	initMaxEnergy = maxEnergy;
}
int AStartGameMode::getInitMaxEnergy() {
	return initMaxEnergy;
}
void AStartGameMode::updateInitMaxEnergy(int modifier) {
	initMaxEnergy += modifier;
}

void AStartGameMode::setUnlockedPieces(TArray<APiece*> allUnlockedPieces) {
	unlockedPieces = allUnlockedPieces;
}

void AStartGameMode::setSelectedPieces(TArray<APiece*> allSelectedPieces) {
	selectedPieces = allSelectedPieces;
}
TArray<APiece*> AStartGameMode::getSelectedPieces() {
	return selectedPieces;
}
bool AStartGameMode::ableToAddAPiece(APiece* aPiece) {
	int currentTotalEnergy = getTotalEnergy(selectedPieces);
	int energyToAdd = aPiece->getEnergyPoint();
	return (currentTotalEnergy + energyToAdd) <= initMaxEnergy;
}
int AStartGameMode::getTotalEnergy(TArray<APiece*> aPiece) {
	int aTotalEnergy = 0;
	for (APiece* eachPiece : selectedPieces) {
		aTotalEnergy += eachPiece->getEnergyPoint();
	}
	return aTotalEnergy;
}
void AStartGameMode::addASelectedPiece(APiece* aPiece) {
	if (ableToAddAPiece(aPiece)) {
		selectedPieces.Add(aPiece);
	}
}
void AStartGameMode::removeASelectedPiece(APiece* aPiece) {
	selectedPieces.Remove(aPiece);
}

