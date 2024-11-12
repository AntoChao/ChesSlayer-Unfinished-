// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjectiveDefense.h"

UMissionObjectiveDefense::UMissionObjectiveDefense() {
	missionObjective = EObjective::EDefense;
}

bool UMissionObjectiveDefense::isObjectiveCompleted(UCSMission* aMission) {
	return isAnyTargetPiecesDied();
}

TArray<UPower*> UMissionObjectiveDefense::selectParticipantPowers(TArray<UPower*> allPowers) {
	return selectRandomPowerByNum(allPowers, selectRandomNumber(3));
}

void UMissionObjectiveDefense::selectTargetPieces(TArray<UPower*> allPowers) {
	UPower* allyPower = selectRandomAllyPower(allPowers);
	APiece* allyLeader = allyPower->getArmyLeader();
	targetPieces.Add(allyLeader);
}

void UMissionObjectiveDefense::generateParticipantInitLocation(TArray<UPower*>& participantPowers,
	UBoard* missionBoard) {
	if (participantPowers.Num() == 2) {
		this->setTwoPowerLocation(participantPowers);
	}
	else {
		this->setThreePowerLocationCenter(participantPowers);
	}
}

void UMissionObjectiveDefense::generateTargetLocations(TArray<UPower*> participantPowers, 
	UBoard* missionBoard) {
	return;
}

