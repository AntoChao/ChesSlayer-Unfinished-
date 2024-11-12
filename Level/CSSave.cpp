// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSSave.h"

UCSSave::UCSSave() {
}

void UCSSave::setLanguage(ELanguage aLanguage) {
	language = aLanguage;
}
ELanguage UCSSave::getLanguage() {
	return language;
}

void UCSSave::setLastTimeDifficulty(int aDifficulty) {
	lastTimeDifficulty = aDifficulty;
}

int UCSSave::getLastTimeDifficulty() {
	return lastTimeDifficulty;
}


void UCSSave::setAlreadyUnlockedPieces(TArray<APiece*> pieces) {
	currentUnlockedPieces = pieces;
}

TArray<APiece*> UCSSave::getAlreadyUnlockedPieces() {
	return currentUnlockedPieces;
}


void UCSSave::setIsNewGame(bool status) {
	isNewGame = status;
}

bool UCSSave::getIsNewGame() {
	return isNewGame;
}


void UCSSave::setPlayerInitPieces(TArray<APiece*> pieces) {
	playerInitPieces = pieces;
}

TArray<APiece*> UCSSave::getPlayerInitPieces() {
	return playerInitPieces;
}


void UCSSave::setCurrentUnlockedPieces(TArray<APiece*> pieces) {
	alreadyUnlockedPieces = pieces;
}

TArray<APiece*> UCSSave::getCurrentUnlockedPieces() {
	return alreadyUnlockedPieces;
}


void UCSSave::setLastTimeAllPowers(TArray<UPower*> powers) {
	lastTimePowers = powers;
}

TArray<UPower*> UCSSave::getLastTimeAllPowers() {
	return lastTimePowers;
}


void UCSSave::setStageNum(int aStageNum) {
	totalStageNum = aStageNum;
}

int UCSSave::getStageNum() {
	return totalStageNum;
}


void UCSSave::setLastTimeStage(int stage) {
	lastTimeStage = stage;
}

int UCSSave::getLastTimeStage() {
	return lastTimeStage;
}


void UCSSave::setAllStages(TArray<UCSStage*> stages) {
	allStages = stages;
}

TArray<UCSStage*> UCSSave::getAllStages() {
	return allStages;
}


void UCSSave::setLastTimeEnemyKilledCount(int count) {
	lastTimeEnemiesKilledCount = count;
}

int UCSSave::getLastTimeEnemyKilledCount() {
	return lastTimeEnemiesKilledCount;
}