// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjectiveSurvival.h"

UMissionObjectiveSurvival::UMissionObjectiveSurvival() {
	missionObjective = EObjective::ESurvival;
	targetTurnNum = 10;
}

bool UMissionObjectiveSurvival::isObjectiveCompleted(UCSMission* aMission) {
	return (aMission->getTurnCount() == targetTurnNum) || isAllTargetPiecesDied();
}

TArray<UPower*> UMissionObjectiveSurvival::selectParticipantPowers(TArray<UPower*> allPowers) {
	return selectRandomPowerByNum(allPowers, selectRandomNumber(3));
}

void UMissionObjectiveSurvival::selectTargetPieces(TArray<UPower*> allPowers) {
	UPower* playerPower = selectRandomAllyPower(allPowers);
	targetPieces = playerPower->getArmy();
}

void UMissionObjectiveSurvival::generateParticipantInitLocation(TArray<UPower*>& participantPowers, 
	UBoard* missionBoard) {
	if (participantPowers.Num() == 2) {
		this->setTwoPowerLocation(participantPowers);
	}
	else {
		this->setThreePowerLocationCenter(participantPowers);
	}
}

void UMissionObjectiveSurvival::generateTargetLocations(TArray<UPower*> participantPowers, 
	UBoard* missionBoard) {
	return;
}

