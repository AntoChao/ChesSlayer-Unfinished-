// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSMission.h"

// gamemode
#include "../Level/GameplayGameMode.h"

// power
#include "../Power/Power.h"

UCSMission::UCSMission() {
	
}

void UCSMission::initializeMission(int aStage) {
	generateRandomObjective();
	setCurrentStage(aStage);
}

void UCSMission::setCurrentStage(int aStage) {
	currentStage = aStage;
}
int UCSMission::getCurrentStage() {
	return currentStage;
}


void UCSMission::setMissionLevel(int aLevel) {
	missionLevel = aLevel;
}
int UCSMission::getMissionLevel() {
	return missionLevel;
}


void UCSMission::setIsBossMission(bool aState) {
	isBossMission = aState;
}

bool UCSMission::getIsBossMission() {
	return isBossMission;
}


void UCSMission::setObjective(UMissionObjective*& aObjective) {
	objective = aObjective;
}

UMissionObjective* UCSMission::getObjective() {
	return objective;
}

void UCSMission::generateRandomObjective() {
	if (!objectiveGenerator) {
		objectiveGenerator = NewObject<UMissionObjectiveGenerator>(this, objectiveGeneratorClass);
	}
	objective = objectiveGenerator->generateARandomMission(this);
}

void UCSMission::generateSpecificObjective(EObjective aObjective) {
	objective = objectiveGenerator->generateASpecificMission(this, aObjective);
}


void UCSMission::setIsMissionCompleted(bool missionState) {
	isMissionCompleted = missionState;
}

bool UCSMission::getIsMissionCompleted() {
	return isMissionCompleted;
}

void UCSMission::checkMissionCompleteness() {
	isMissionCompleted = objective->isObjectiveCompleted(this);
}


void UCSMission::setIsMissionWon(bool missionState) {
	isMissionWon = missionState;
}

bool UCSMission::getIsMissionWon() {
	return isMissionWon;
}


void UCSMission::setIsDay(bool dayState) {
	isDay = dayState;
}

bool UCSMission::getIsDay() {
	return isDay;
}


void UCSMission::setParticipantPowers(TArray<UPower*>& powers) {
	participantsPowers = powers;
}

TArray<UPower*>& UCSMission::getParticipantPowers() {
	return participantsPowers;
}

// Board
void UCSMission::setMissionBoard(UBoard* aBoard) {
	missionBoard = aBoard;
}
UBoard*& UCSMission::getMissionBoard() {
	return missionBoard;
}

void UCSMission::generateBoard() {
	if (!boardGenerator) {
		boardGenerator = NewObject<UBoardGenerator>(this, boardGeneratorClass);
	}
	missionBoard = boardGenerator->generateBoard(this, currentStage);
}

// mission proceding methods
void UCSMission::orderParticipantPowers() {
	participantsPowers.Sort([](UPower& aPower, UPower& anotherPower) {
		return aPower.getArmyCurrentEnergy() > anotherPower.getArmyCurrentEnergy();
	});
}

void UCSMission::startPowerTurn() {
	checkMissionCompleteness();
	if (!isMissionCompleted) {
		// the start of a circle
		if (currentParticipantIndex % participantsPowers.Num() == 0) {
			turnCount++;
			orderParticipantPowers();
		}
		UCSMission* thisPointer = this;
		participantsPowers[currentParticipantIndex]->startTurn(thisPointer);
		currentParticipantIndex++;
	}
	else {
		missionCompletedEffect();
	}
}

void UCSMission::powerActionFinished(EPowerName powerName) {
	checkMissionCompleteness();
	if (isMissionCompleted) {
		missionCompletedEffect();
	}
}

void UCSMission::powerTurnFinished(EPowerName powerName) {
	checkMissionCompleteness();
	if (isMissionCompleted) {
		missionCompletedEffect();
	}
	else {
		startPowerTurn();
	}
}

void UCSMission::missionCompletedEffect() {
	if (isBossMission) {
		AGameplayGameMode* currentGameMode = Cast<AGameplayGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

		if (currentGameMode) {
			currentGameMode->startNextStage();
		}
	}
}


void UCSMission::setTurnCount(int turnAmount) {
	turnCount = turnAmount;
}

int UCSMission::getTurnCount() {
	return turnCount;
}

void UCSMission::updateTurnCount(int modifier) {
	turnCount += modifier;
}