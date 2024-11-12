// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjectiveEscort.h"

UMissionObjectiveEscort::UMissionObjectiveEscort() {
	missionObjective = EObjective::EEscort;
}

bool UMissionObjectiveEscort::isObjectiveCompleted(UCSMission* aMission) {
	if (isAnyTargetPiecesDied()) {
		aMission->setIsMissionWon(false);
		return true;
	}
	for (FLocation eachTargetLocation : targetLocations) {
		for (APiece* eachTargetPiece : targetPieces) {
			if (eachTargetPiece->getPieceSquare()->getInBoardLocation().isEqual(eachTargetLocation)) {
				aMission->setIsMissionWon(true);
				return true;
			}
		}
	}
	return false;
}

TArray<UPower*> UMissionObjectiveEscort::selectParticipantPowers(TArray<UPower*> allPowers) {
	return selectRandomPowerByNum(allPowers, selectRandomNumber(3));
}

void UMissionObjectiveEscort::selectTargetPieces(TArray<UPower*> allPowers) {
	UPower* allyPower = selectRandomAllyPower(allPowers);
	APiece* allyLeader = allyPower->getArmyLeader();
	targetPieces.Add(allyLeader);
}

void UMissionObjectiveEscort::generateParticipantInitLocation(TArray<UPower*>& participantPowers, 
	UBoard* missionBoard) {
	if (participantPowers.Num() == 2) {
		setTwoPowerLocation(participantPowers);
	}
	else {
		setThreePowerLocationSides(participantPowers);
	}
}

/* should check the minimal distance between*/
void UMissionObjectiveEscort::generateTargetLocations(TArray<UPower*> participantPowers,
	UBoard* missionBoard) {

	FLocation aRandomLocation = getARandomSideLocation();
	applyNoiseToLocation(aRandomLocation);
	targetLocations.Add(aRandomLocation);
}

