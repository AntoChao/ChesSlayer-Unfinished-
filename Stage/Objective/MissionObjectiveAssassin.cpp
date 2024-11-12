// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjectiveAssassin.h"

UMissionObjectiveAssassin::UMissionObjectiveAssassin() {
	missionObjective = EObjective::EAssassination;
}

bool UMissionObjectiveAssassin::isObjectiveCompleted(UCSMission* aMission) {
	return isAllTargetPiecesDied();
}

TArray<UPower*> UMissionObjectiveAssassin::selectParticipantPowers(TArray<UPower*> allPowers) {
	return selectRandomPowerByNum(allPowers, selectRandomNumber(3));
}

/* Assassin missions is kill the enemy leader*/
void UMissionObjectiveAssassin::selectTargetPieces(TArray<UPower*> allPowers) {
	UPower* enemyPower = selectRandomEnemyPower(allPowers);
	APiece* enemyLeader = enemyPower->getArmyLeader();
	targetPieces.Add(enemyLeader);
}

/* the distance has to be far away*/
void UMissionObjectiveAssassin::generateParticipantInitLocation(TArray<UPower*>& participantPowers,
	UBoard* aMissionBoard) {
	if (participantPowers.Num() == 2) {
		setTwoPowerLocation(participantPowers);
	}
	else {
		setThreePowerLocationSides(participantPowers);
	}
}

void UMissionObjectiveAssassin::generateTargetLocations(TArray<UPower*> participantPowers,
	UBoard* aMissionBoard) {
	return;
}