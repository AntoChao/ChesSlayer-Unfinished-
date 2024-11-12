// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjectiveDefeat.h"

UMissionObjectiveDefeat::UMissionObjectiveDefeat() {
	missionObjective = EObjective::EDefeat;
}

bool UMissionObjectiveDefeat::isObjectiveCompleted(UCSMission* aMission) {
	return isAllTargetPiecesDied();
}

TArray<UPower*> UMissionObjectiveDefeat::selectParticipantPowers(TArray<UPower*> allPowers) {
	return selectRandomPowerByNum(allPowers, selectRandomNumber(3));
}

void UMissionObjectiveDefeat::selectTargetPieces(TArray<UPower*> allPowers) {
	UPower* enemyPower = selectRandomEnemyPower(allPowers);
	targetPieces = enemyPower->getArmy();
}

void UMissionObjectiveDefeat::generateParticipantInitLocation(TArray<UPower*>& participantPowers, 
	UBoard* missionBoard) {
	if (participantPowers.Num() == 2) {
		this->setTwoPowerLocation(participantPowers);
	}
	else {
		this->setThreePowerLocationSides(participantPowers);
	}
}

void UMissionObjectiveDefeat::generateTargetLocations(TArray<UPower*> participantPowers, 
	UBoard* missionBoard) {
	return;
}
