// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSInstance.h"
#include "CSSave.h"
#include "CSGameMode.h"

UCSInstance::UCSInstance() {
}
 
void UCSInstance::Init() {
	Super::Init();

	// intiialize singleton classes
		
	UPieceGenerator::SetPieceGeneratorClass(PieceGeneratorClass);
	UPieceAbilityGenerator::SetPieceAbilityGeneratorClass(PieceAbilityGeneratorClass);

	// load previous game data
	loadSaveData();
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("----------------------------------------------"));
	// initialize instance values
	openNextLevel(EGameMode::EInitGameMode);
}

void UCSInstance::Shutdown() {
	Super::Shutdown();

	setSaveData();
}

void UCSInstance::loadSaveData() {
	if (UGameplayStatics::DoesSaveGameExist(TEXT("GameInstanceSlot"), 0)) {
		// get the save object
		UCSSave* gameSave = Cast<UCSSave>(UGameplayStatics::
			LoadGameFromSlot(TEXT("GameInstanceSlot"), 0));

		if (gameSave) {
			
			isFirstTimeOpening = false;
			// set values from CSSave
			gameLanguage = gameSave->getLanguage();
			isLastGameFinished = gameSave->getIsNewGame();
			unlockedPieces = gameSave->getAlreadyUnlockedPieces();
			currentDifficulty = gameSave->getLastTimeDifficulty();
			unlockedPieces = gameSave->getAlreadyUnlockedPieces();
			currentAllPowers = gameSave->getLastTimeAllPowers();
			currentStage = gameSave->getLastTimeStage();
			currentEnemiesKilledCount = gameSave->getLastTimeEnemyKilledCount();
			newUnlockedPieces = gameSave->getCurrentUnlockedPieces();
		}
	}
	else {
		isFirstTimeOpening = true;
		// createInitUnloackedPieces();
		gameLanguage = ELanguage::EEnglish;
	}
}

// just update the value after each mission finished
void UCSInstance::setSaveData() {
	loadGameModeAttributes();
	if (UGameplayStatics::DoesSaveGameExist(TEXT("GameInstanceSlot"), 0)) {
		// get the save object
		UCSSave* gameSave = Cast<UCSSave>(UGameplayStatics::
			LoadGameFromSlot(TEXT("GameInstanceSlot"), 0));

		if (gameSave) {
			gameSave->setLanguage(gameLanguage);
			gameSave->setIsNewGame(isLastGameFinished);
			gameSave->setLastTimeDifficulty(currentDifficulty);
			gameSave->setAlreadyUnlockedPieces(unlockedPieces);
			gameSave->setLastTimeAllPowers(currentAllPowers);
			gameSave->setLastTimeStage(currentStage);
			gameSave->setLastTimeEnemyKilledCount(currentEnemiesKilledCount);
			gameSave->setCurrentUnlockedPieces(newUnlockedPieces);

			UGameplayStatics::SaveGameToSlot(gameSave, TEXT("GameInstance"), 0);
		}
	}
}

void UCSInstance::loadGameModeAttributes() {
	// update the instance values based on current Gamemode
	UWorld* World = GetWorld();
	if (World) {
		AGameModeBase* GameModeBase = UGameplayStatics::GetGameMode(World);
		ACSGameMode* currentCSGameMode = Cast<ACSGameMode>(GameModeBase);
		if (currentCSGameMode) {
			currentCSGameMode->updateInstance();
		}
	}
}

void UCSInstance::loadGameModeAttributesDirect(ACSGameMode* currentCSGameMode) {
	if (currentCSGameMode) {
		currentCSGameMode->updateInstance();
	}
}

void UCSInstance::openNextLevel(EGameMode nextGameMode) {
	switch (nextGameMode) {
	case EGameMode::EInitGameMode: {
		currentGameMode = EGameMode::EInitGameMode;
		UGameplayStatics::OpenLevel(this, FName("InitGameLevel"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("open Init Level"));
		break;
	}
	case EGameMode::EStartGameMode: {
		currentGameMode = EGameMode::EStartGameMode;
		UGameplayStatics::OpenLevel(this, FName("StartGameLevel"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("open Start Level"));
		break;
	}
	case EGameMode::EGameplayGameMode: {
		currentGameMode = EGameMode::EGameplayGameMode;
		UGameplayStatics::OpenLevel(this, FName("GameplayLevel"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("open Gameplay Level"));
		break;
	}
	case EGameMode::EPostgameGameMode: {
		currentGameMode = EGameMode::EPostgameGameMode;
		UGameplayStatics::OpenLevel(this, FName("PostGameLevel"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("open Postgame Level"));
		break;
	}
	default:
		break;
	}

	InitPowerPieces();
}

// Pieces initializations
void UCSInstance::resetAllPieces() {
	unlockedPieces = {};
}

void UCSInstance::createInitUnloackedPieces() {
	resetAllPieces();
	UPieceGenerator* pieceGenerator = UPieceGenerator::GetPieceGeneratorInstance();
	if (pieceGenerator) {
		for (FName eachName : unlockedPieceNames) {
			APiece* generatedPiece = pieceGenerator->generateSpecificPieceByName(GetWorld(), eachName);
			unlockedPieces.Add(generatedPiece);
		}
	}

}

void UCSInstance::InitPowerPieces() {
	// reset each power piece
}

/* setters & getters*/
void UCSInstance::setIsFirstTimeOpening(bool gameStatus) {
	isFirstTimeOpening = gameStatus;
}
bool UCSInstance::getIsFirstTimeOpening() {
	return isFirstTimeOpening;
}

void UCSInstance::setGameLanguage(ELanguage aLanguage) {
	gameLanguage = aLanguage;
}
ELanguage UCSInstance::getGameLanguage() {
	return gameLanguage;
}

void UCSInstance::setIsLastGameFinished(bool gameStatus) {
	isLastGameFinished = gameStatus;
}
bool UCSInstance::getIsLastGameFinished() {
	return isLastGameFinished;
}

void UCSInstance::setCurrentDifficulty(int aDifficulty) {
	currentDifficulty = aDifficulty;
}

int UCSInstance::getCurrentDifficulty() {
	return currentDifficulty;
}

void UCSInstance::setUnlockedPieces(TArray<APiece*> pieces) {
	unlockedPieces = pieces;
}

TArray<APiece*> UCSInstance::getUnlockedPieces() {
	createInitUnloackedPieces();

	for (APiece* eachUnlockedPiece : unlockedPieces) {
		if (eachUnlockedPiece) {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("unlocked piece is valid before getter"));
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("unlocked piece is NOT valid before getter"));
		}
	}
	return unlockedPieces;
}


void UCSInstance::setCurrentPowers(TArray<UPower*> allPowers) {
	currentAllPowers = allPowers;
}

TArray<UPower*> UCSInstance::getCurrentPowers() {
	return currentAllPowers;
}

void UCSInstance::setIsGameWon(bool gameState) {
	isGameWon = gameState;
}

bool UCSInstance::getIsGameWon() {
	return isGameWon;
}

void UCSInstance::setStageNum(int stageNum) {
	totalStageNum = stageNum;
}
int UCSInstance::getStageNum() {
	return totalStageNum;
}

void UCSInstance::setCurrentStageNum(int aCurrentStage) {
	currentStage = aCurrentStage;
}
int UCSInstance::getCurrentStageNum() {
	return currentStage;
}

void UCSInstance::setAllStages(TArray<UCSStage*> allGeneratedStages) {
	allStages = allGeneratedStages;
}
TArray<UCSStage*> UCSInstance::getAllStages() {
	return allStages;
}


void UCSInstance::setTotalEnemiesKilled(int killCount) {
	currentEnemiesKilledCount = killCount;
}
int UCSInstance::getTotalEnemiesKilled() {
	return currentEnemiesKilledCount;
}

void UCSInstance::setNewUnlockedPieces(TArray<APiece*> pieces) {
	newUnlockedPieces = pieces;
}
TArray<APiece*> UCSInstance::getNewUnlockedPieces() {
	return newUnlockedPieces;
}