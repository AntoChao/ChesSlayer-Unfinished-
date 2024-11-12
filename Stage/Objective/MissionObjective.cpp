// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjective.h"

#include "../CSMission.h"
#include "../../Power/Power.h"

UMissionObjective::UMissionObjective() {

}

void UMissionObjective::setObjective(EObjective aObjective) {
	missionObjective = aObjective;
}

EObjective UMissionObjective::getObjective() {
	return missionObjective;
}

/*at the moment of initialization, EObjective is already defined*/
void UMissionObjective::initializeObjective(UCSMission*& aMission) {
	// select participant powers
	TArray<UPower*> participants = selectParticipantPowers(aMission->getParticipantPowers());
	aMission->setParticipantPowers(participants);
	
	// select target pieces
	selectTargetPieces(participants);

	generateTargetLocations(aMission->getParticipantPowers(), 
		aMission->getMissionBoard());

	// set locations
	initializeAllLocation(aMission->getMissionBoard());
	initializeLocationNoise(aMission->getCurrentStage());
	generateParticipantInitLocation(aMission->getParticipantPowers(), 
		aMission->getMissionBoard());	
}


// support power functions
void UMissionObjective::selectPowerByName(TArray<UPower*>& allPowers,
	TArray<EPowerName> powerNames) {
	if (!powerNames.Contains(EPowerName::EPlayer)) {
		powerNames.Add(EPowerName::EPlayer);
	}

	bool found;
	for (UPower* eachPower : allPowers) {
		found = false;
		for (EPowerName eachPowerName : powerNames) {
			if (eachPower->getPowerName() == eachPowerName) {
				found = true;
				break;
			}
		}
		if (!found) {
			allPowers.Remove(eachPower);
		}
	}
}

int UMissionObjective::selectRandomNumber(int maxNum) {
	if (maxNum <= 2) {
		return 2;
	}
	else {
		return FMath::RandRange(2, maxNum);
	}
}

TArray<UPower*> UMissionObjective::selectRandomPowerByNum(TArray<UPower*>& allPowers, int maxNum) {
	int numberToSelect = selectRandomNumber(maxNum);
	TArray<EPowerName> powerNameSelected;
	powerNameSelected.Add(EPowerName::EPlayer);
	numberToSelect--;

	EPowerName aRandomPowerName;
	while (numberToSelect != 0) {
		aRandomPowerName = getRandomPowerName();
		if (!powerNameSelected.Contains(aRandomPowerName)) {
			powerNameSelected.Add(aRandomPowerName);
			numberToSelect--;
		}
	}

	selectPowerByName(allPowers, powerNameSelected);

	return allPowers;
}

EPowerName UMissionObjective::getRandomPowerName() {
	return static_cast<EPowerName>(FMath::RandRange(1, 3));
}


TArray<UPower*> UMissionObjective::selectParticipantPowers(TArray<UPower*> allPowers) {
	return allPowers;
}

void UMissionObjective::generateParticipantInitLocation(TArray<UPower*>& participantPowers,
	UBoard* missionBoard) {
	return;
}

// support location functions
void UMissionObjective::initializeAllLocation(UBoard* missionBoard) {
	int gridSize = missionBoard->getBoardWidth() / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x = (gridSize * j + gridSize * (j + 1)) / 2;
			int y = (gridSize * i + gridSize * (i + 1)) / 2;
			allLocations.Add(FLocation(x, y));
		}
	}
}

void UMissionObjective::initializeLocationNoise(int aCurrentStage) {
	initLocationNoise = initLocationNoise - 1 + aCurrentStage;
}

	/*get a random l, ld, d, rd, r, ru, u, lu, c location*/
FLocation UMissionObjective::getARandomLocation() {
	return allLocations[FMath::RandRange(0, 8)];
}

FLocation UMissionObjective::getARandomSideLocation() {
	int locationSelected = FMath::RandRange(0, 7);
	if (locationSelected >= 4) {
		locationSelected++;
	}
	return allLocations[locationSelected];
}

FLocation UMissionObjective::getCenterLocation() {
	return allLocations[4];
}

void UMissionObjective::applyNoiseToAllLocation(TArray<FLocation>& allLocationToApply) {
	for (FLocation& aLocation : allLocationToApply) {
		applyNoiseToLocation(aLocation);
	}
}

void UMissionObjective::applyNoiseToLocation(FLocation& aLocationsToApply) {
	int xNoise = FMath::RandRange(-initLocationNoise, +initLocationNoise);
	int yNoise = FMath::RandRange(-initLocationNoise, +initLocationNoise);
	aLocationsToApply.x = aLocationsToApply.x + xNoise;
	aLocationsToApply.y = aLocationsToApply.y + yNoise;
}

int UMissionObjective::calculateDistance(FLocation aLocation, FLocation anotherLocation) {
	return FMath::Abs(aLocation.x - anotherLocation.x) +
		FMath::Abs(aLocation.y - anotherLocation.y);
}

void UMissionObjective::setTwoPowerLocation(TArray<UPower*> participantPowers) {
	FLocation aLocation = getARandomSideLocation();
	FLocation anotherLocation;
	do {
		anotherLocation = getARandomSideLocation();
	} while (aLocation.isEqual(anotherLocation));

	applyNoiseToLocation(aLocation);
	applyNoiseToLocation(anotherLocation);

	participantPowers[0]->setInitLocation(aLocation);
	participantPowers[1]->setInitLocation(anotherLocation);
}

void UMissionObjective::setThreePowerLocationSides(TArray<UPower*> participantPowers) {
	FLocation locationOne = getARandomSideLocation();
	
	FLocation locationTwo;
	do {
		locationTwo = getARandomSideLocation();
	} while (locationOne.isEqual(locationTwo));
	
	FLocation locationThree;
	do {
		locationThree = getARandomSideLocation();
	} while (locationOne.isEqual(locationThree) || locationTwo.isEqual(locationThree));
	
	applyNoiseToLocation(locationOne);
	applyNoiseToLocation(locationTwo);
	applyNoiseToLocation(locationThree);

	participantPowers[0]->setInitLocation(locationOne);
	participantPowers[1]->setInitLocation(locationTwo);
	participantPowers[1]->setInitLocation(locationThree);
}

void UMissionObjective::setThreePowerLocationCenter(TArray<UPower*> participantPowers) {
	FLocation locationOne = getARandomSideLocation();

	FLocation locationTwo;
	do {
		locationTwo = getARandomSideLocation();
	} while (locationOne.isEqual(locationTwo));

	FLocation locationThree;
	do {
		locationThree = getARandomSideLocation();
	} while (locationOne.isEqual(locationThree) || locationTwo.isEqual(locationThree));

	applyNoiseToLocation(locationOne);
	applyNoiseToLocation(locationTwo);
	applyNoiseToLocation(locationThree);

	participantPowers[0]->setInitLocation(locationOne);
	participantPowers[1]->setInitLocation(locationTwo);
	participantPowers[1]->setInitLocation(locationThree);

	int centerPower = FMath::RandRange(0, 2);
	FLocation centerLocation = getCenterLocation();
	applyNoiseToLocation(centerLocation);

	participantPowers[centerPower]->setInitLocation(centerLocation);
}

// in game objective check
bool UMissionObjective::isObjectiveCompleted(UCSMission* aMission) {
	return false;
}

void UMissionObjective::selectTargetPieces(TArray<UPower*> allPowers) {
	return;
}

TArray<APiece*> UMissionObjective::selectAllAILeaderPieces(TArray<UPower*> allPowers) {
	TArray<APiece*> leaderPieces;
	for (UPower* eachPower : allPowers) {
		if (eachPower->getPowerName() != EPowerName::EPlayer) {
			for (APiece* eachPiece : eachPower->getArmy()) {
				if (eachPiece->getIfIsArmyLeader()) {
					leaderPieces.Add(eachPiece);
				}
			}
		}
	}
	return leaderPieces;
}

UPower* UMissionObjective::selectPlayerPower(TArray<UPower*> allPowers) {
	return allPowers[0];
}

UPower* UMissionObjective::selectRandomAllyPower(TArray<UPower*> allPowers) {
	UPower* aPlayerPower = nullptr;
	TArray<UPower*> allyPowers;
	for (UPower* eachPower : allPowers) {
		if (eachPower->getPowerName() != EPowerName::EPlayer) {
			if (eachPower->getRelationship()->getPlayerRelationship() == ERelationship::EAlly) {
				allyPowers.Add(eachPower);
			}
		}
		else {
			aPlayerPower = eachPower;
		}
	}
	
	if (allyPowers.Num() != 0) {
		return allyPowers[FMath::RandRange(0, allyPowers.Num() - 1)];
	}
	else {
		return aPlayerPower;
	}
}

UPower* UMissionObjective::selectRandomNeutroPower(TArray<UPower*> allPowers) {
	UPower* aPlayerPower = nullptr;
	TArray<UPower*> neutroPowers;
	for (UPower* eachPower : allPowers) {
		if (eachPower->getPowerName() != EPowerName::EPlayer) {
			if (eachPower->getRelationship()->getPlayerRelationship() == ERelationship::ENeutro) {
				neutroPowers.Add(eachPower);
			}
		}
		else {
			aPlayerPower = eachPower;
		}
	}
	if (neutroPowers.Num() != 0) {
		return neutroPowers[FMath::RandRange(0, neutroPowers.Num() - 1)];
	}
	else {
		return aPlayerPower;
	}
}

UPower* UMissionObjective::selectRandomEnemyPower(TArray<UPower*> allPowers) {
	UPower* aPlayerPower = nullptr;
	TArray<UPower*> enemyPowers;
	for (UPower* eachPower : allPowers) {
		if (eachPower->getPowerName() != EPowerName::EPlayer) {
			if (eachPower->getRelationship()->getPlayerRelationship() == ERelationship::EEnemy) {
				enemyPowers.Add(eachPower);
			}
		}
		else {
			aPlayerPower = eachPower;
		}
	}
	if (enemyPowers.Num() != 0) {
		return enemyPowers[FMath::RandRange(0, enemyPowers.Num() - 1)];
	}
	else {
		return aPlayerPower;
	}
}

APiece* UMissionObjective::selectRandomArmyPiece(UPower* UPower) {
	TArray<APiece*> powerArmy = UPower->getArmy();
	if (powerArmy.Num() != 0) {
		return powerArmy[FMath::RandRange(0, powerArmy.Num() - 1)];
	}
	else {
		return nullptr;
	}
}

APiece* UMissionObjective::selectRandomPiece(TArray<APiece*> allPieces) {
	return allPieces[FMath::RandRange(0, allPieces.Num() - 1)];
}

bool UMissionObjective::isAllTargetPiecesDied() {
	for (APiece* eachPiece : targetPieces) {
		if (eachPiece->getIsAlive()) {
			return false;
		}
	}
	return true;
}

bool UMissionObjective::isAnyTargetPiecesDied() {
	for (APiece* eachPiece : targetPieces) {
		if (!eachPiece->getIsAlive()) {
			return true;
		}
	}
	return false;
}

void UMissionObjective::generateTargetLocations(TArray<UPower*> participantPowers,
	UBoard* missionBoard) {
	return;
}

