// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjectiveCapture.h"

UMissionObjectiveCapture::UMissionObjectiveCapture() {
	missionObjective = EObjective::ECapture;
}

bool UMissionObjectiveCapture::isObjectiveCompleted(UCSMission* aMission) {
	for (FLocation eachTargetLocation : targetLocations) {
		for (APiece* eachTargetPiece : targetPieces) {
			if (eachTargetPiece->getPieceSquare()->getInBoardLocation().isEqual(eachTargetLocation)) {
				return true;
			}
		}
	}
	return false;
}

TArray<UPower*> UMissionObjectiveCapture::selectParticipantPowers(TArray<UPower*> allPowers) {
	return selectRandomPowerByNum(allPowers, selectRandomNumber(3));
}

void UMissionObjectiveCapture::selectTargetPieces(TArray<UPower*> allPowers) {
	UPower* enemyPower = selectRandomEnemyPower(allPowers);
	APiece* enemyLeader = enemyPower->getArmyLeader();
	targetPieces.Add(enemyLeader);
}

void UMissionObjectiveCapture::generateParticipantInitLocation(TArray<UPower*>& participantPowers,
	UBoard* missionBoard) {
	if (participantPowers.Num() == 2) {
		setTwoPowerLocation(participantPowers);
	}
	else {
		setThreePowerLocationCenter(participantPowers);
	}
}

void UMissionObjectiveCapture::generateTargetLocations(TArray<UPower*> participantPowers,
	UBoard* missionBoard){
	
	FLocation aRandomLocation = getARandomSideLocation();
	applyNoiseToLocation(aRandomLocation);
	targetLocations.Add(aRandomLocation);
}

