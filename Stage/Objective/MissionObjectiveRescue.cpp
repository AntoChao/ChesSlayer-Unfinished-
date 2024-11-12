// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjectiveRescue.h"

UMissionObjectiveRescue::UMissionObjectiveRescue() {
	missionObjective = EObjective::ERescue;
}

bool UMissionObjectiveRescue::isObjectiveCompleted(UCSMission* aMission) {
	for (APiece* eachTargetPiece : targetPieces) {
		if (eachTargetPiece->getIsWaitingForRescue()) {
			return false;
		}
	}
	return true;
}

TArray<UPower*> UMissionObjectiveRescue::selectParticipantPowers(TArray<UPower*> allPowers) {
	return selectRandomPowerByNum(allPowers, selectRandomNumber(3));
}

void UMissionObjectiveRescue::selectTargetPieces(TArray<UPower*> allPowers) {
	UPower* allyPower = selectRandomAllyPower(allPowers);
	APiece* allyLeader = allyPower->getArmyLeader();
	targetPieces.Add(allyLeader);
}

void UMissionObjectiveRescue::generateParticipantInitLocation(TArray<UPower*>& participantPowers,
	UBoard* missionBoard) {
	if (participantPowers.Num() == 2) {
		this->setTwoPowerLocation(participantPowers);
	}
	else {
		this->setThreePowerLocationSides(participantPowers);
	}
}

void UMissionObjectiveRescue::generateTargetLocations(TArray<UPower*> participantPowers,
	UBoard* missionBoard) {
	return;
}