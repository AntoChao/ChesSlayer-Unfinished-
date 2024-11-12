// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIPower.h"

UAIPower::UAIPower() {

}

void UAIPower::InitPower(int aDifficulty, int currentStage, TArray<APiece*> selectedPieces) {
	setMaxArmyEnergy(aDifficulty, currentStage);
	fillArmyByRandom();
}

void UAIPower::setMaxArmyEnergy(int difficulty, int currentStage) {
	int aNumber = 0;
	aNumber = 5 * difficulty;
	armyMaxEnergy = getNoisedValue(aNumber, armyDefaultNoise);
}