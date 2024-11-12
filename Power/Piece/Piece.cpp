// Copyright Epic Games, Inc. All Rights Reserved.

#include "Piece.h"

// power 
#include "../Power.h"

// board square
#include "../../Stage/Board/BoardSquare.h"

APiece::APiece() {
	isAlive = true;
}

void APiece::initPiece(UPower*& aPower) {
	setPowerBelong(aPower);
	// initializeAbilityGenerator();
	initializeAllAbilities();
}

// piece in game info methods
FName APiece::getPieceName() {
	return pieceName;
}

void APiece::setPowerBelong(UPower*& UPower) {
	powerBelong = UPower;
}

UPower* APiece::getPowerBelong() {
	return powerBelong;
}

bool APiece::isSamePower(APiece* anotherPiece) {
	return powerBelong == anotherPiece->getPowerBelong();
}

bool APiece::isAllyPower(APiece* anotherPiece) {
	ERelationship relation = powerBelong->getRelationship()->getRelationship(anotherPiece->getPowerBelong()->getPowerName());
	return relation == ERelationship::EAlly;
}

bool APiece::isNeutroPower(APiece* anotherPiece) {
	ERelationship relation = powerBelong->getRelationship()->getRelationship(anotherPiece->getPowerBelong()->getPowerName());
	return relation == ERelationship::ENeutro;
}

bool APiece::isEnemyPower(APiece* anotherPiece) {
	ERelationship relation = powerBelong->getRelationship()->getRelationship(anotherPiece->getPowerBelong()->getPowerName());
	return relation == ERelationship::EEnemy;
}


	// select army leader
void APiece::setIsArmyLeader(bool state) {
	isArmyLeader = state;
}

bool APiece::getIfIsArmyLeader() {
	return isArmyLeader;
}

void APiece::setSurvivedTime(int aNum) {
	survivedTime = aNum;
}

int APiece::getSurvivedTime() {
	return survivedTime;
}

void APiece::updateSurvivedTime(int modifier) {
	survivedTime += modifier;
}


void APiece::setViewPoint(int aNewValue) {
	viewPoint = aNewValue;
}

int APiece::getViewPoint() {
	return viewPoint;
}

void APiece::updateViewPoint(int modifier) {
	viewPoint += modifier;
}

void APiece::updateFogOfWar(UBoard*& revealedBoard) {
	if (revealedBoard) {
		int boardWidth = revealedBoard->getBoardWidth();
		int boardHeight = revealedBoard->getBoardHeight();

		for (int y = -viewPoint; y <= viewPoint; ++y) {
			for (int x = -viewPoint; x <= viewPoint; ++x) {
				if (FMath::Abs(x) + FMath::Abs(y) <= viewPoint) {
					FLocation targetLocation = pieceSquare->getInBoardLocation().add(FLocation(x, y));
					if (revealedBoard->isBoardSquareValid(targetLocation)) {
						ABoardSquare* targetSquare = revealedBoard->getBoardSquareAtLocation(targetLocation);
						targetSquare->setIsRevealed(true);
					}
				}
			}
		}
	}
}


void APiece::setMovePoint(int aNewValue) {
	movePoint = aNewValue;
}

int APiece::getMovePoint() {
	return movePoint;
}

void APiece::updateMovePoint(int modifier) {
	movePoint += modifier;
}

void APiece::setCurrentMovePoint(int aNewValue) {
	currentMovePoint = aNewValue;
}

int APiece::getCurrentMovePoint() {
	return currentMovePoint;
}

void APiece::updateCurrentMovePoint(int modifier) {
	currentMovePoint += modifier;

	completedOneAction();
	if (currentMovePoint == 0) {
		noMovePointLeftEffect();
	}
}

void APiece::resetCurrentMovePoint() {
	currentMovePoint = movePoint;
}

void APiece::completedOneAction() {
	powerBelong->endAction();
}

void APiece::noMovePointLeftEffect() {
	powerBelong->endTurn();
}


void APiece::setEnergyPoint(int aNewValue) {
	energyPoint = aNewValue;
}

int APiece::getEnergyPoint() {
	return energyPoint;
}

void APiece::updateEnergyPoint(int modifier) {
	energyPoint += modifier;
}


void APiece::setCurrentEnergyPoint(int aNewValue) {
	currentEnergyPoint = aNewValue;
}

int APiece::getCurrentEnergyPoint() {
	return currentEnergyPoint;
}

void APiece::updateCurrentEnergyPoint(int modifier) {
	currentEnergyPoint += modifier;
	powerBelong->updateCurrentAmryEnergy(modifier);
}

void APiece::resetCurrentEnergyPoint() {
	currentEnergyPoint = energyPoint;
}

	// status
void APiece::resetAllStatus() {
	allStatus = {};
}

void APiece::resetTemporaryStatus() {
	for (UPieceStatus* eachStatus : allStatus) {
		if (!eachStatus->getIfIsPersistent()) {
			removeStatus(eachStatus);
		}
	}
}

void APiece::addStatus(UPieceStatus* aStatus) {
	allStatus.Add(aStatus);
}

void APiece::removeStatus(UPieceStatus* aStatus) {
	allStatus.Remove(aStatus);
}

void APiece::applyAllStatus() {
	for (UPieceStatus* eachStatus : allStatus) {
		eachStatus->applyStatus(this);
	}
}

	// ability methods
void APiece::setLastAbilityUsed(EAbilitySelected anAbility) {
	lastUsedAbility = anAbility;
}

EAbilitySelected APiece::getLastAbilityUsed() {
	return lastUsedAbility;
}


	// should never be changed before
/*
void APiece::initializeAbilityGenerator() {
	if (abilityGeneratorClass) {
		abilityGenerator = NewObject<UPieceAbilityGenerator>(this, abilityGeneratorClass);
	}
}*/

void APiece::initializeAllAbilities() {

	UPieceAbilityGenerator* abilityGenerator = UPieceAbilityGenerator::GetPieceAbilityGeneratorInstance();

	if (abilityGenerator) {
		APiece* tempPointer = this;
		defaultAbility = abilityGenerator->generateASpecificAbility(tempPointer, initDefaultAbilityName);
		abilityOne = abilityGenerator->generateASpecificAbility(tempPointer, initAbilityOneName);
		abilityTwo = abilityGenerator->generateASpecificAbility(tempPointer, initAbilityTwoName);
	}
}


void APiece::setDefaultAbility(UPieceAbility* aAbility) {
	defaultAbility = aAbility;
}

UPieceAbility* APiece::getDefaultAbility() {
	return defaultAbility;
}

void APiece::setAbilityOne(UPieceAbility* aAbility) {
	APiece* tempPointer = this;
	if (isSettingSameAbility(abilityOne, aAbility)) {
		swapAbilityOneTwo();
	}
	else {
		if (abilityOne) {
			abilityOne->unequipAbilityEffect(tempPointer);
		}
		if (aAbility) {
			abilityOne = aAbility;
			aAbility->equipAbilityEffect(tempPointer);
		}
	}
}

UPieceAbility* APiece::getAbilityOne() {
	return abilityOne;
}

void APiece::setAbilityTwo(UPieceAbility* aAbility) {
	APiece* tempPointer = this;
	if (isSettingSameAbility(abilityTwo, aAbility)) {
		swapAbilityOneTwo();
	}
	else {
		if (abilityTwo) {
			abilityTwo->unequipAbilityEffect(tempPointer);
		}
		if (aAbility) {
			abilityTwo = aAbility;
			aAbility->equipAbilityEffect(tempPointer);
		}
	}
}

UPieceAbility* APiece::getAbilityTwo() {
	return abilityTwo;
}

bool APiece::isSettingSameAbility(UPieceAbility* aAbility, 
	UPieceAbility* anotherAbility) {
	return aAbility->getAbilityName() == anotherAbility->getAbilityName();
}

void APiece::swapAbilityOneTwo() {
	UPieceAbility* tempAbility = abilityOne;
	abilityOne = abilityTwo;
	abilityTwo = tempAbility;
}

// piece mission methods
void APiece::setIsSelected(bool pieceState) {
	isSelected = pieceState;
	if (isSelected) {
		selectedEffect();
	}
	else {
		unselectedEffect();
	}
}

bool APiece::getIsSelected() {
	return isSelected;
}

void APiece::selectedEffect() {
	return;
}

void APiece::unselectedEffect() {
	return;
}


void APiece::setIsAlive(bool pieceState) {
	isAlive = pieceState;
}

bool APiece::getIsAlive() {
	return isAlive;
}


void APiece::setPieceSquare(ABoardSquare* aSquare) {
	pieceSquare = aSquare;

	// location change
	bool bSweep = true; // Enable collision checking
	FHitResult HitResult;
	SetActorLocation(aSquare->GetActorLocation(), bSweep, &HitResult);
}

ABoardSquare* APiece::getPieceSquare() {
	return pieceSquare;
}


void APiece::setIsWaitingForRescue(bool state) {
	isWaitingForRescue = state;
}

bool APiece::getIsWaitingForRescue() {
	return isWaitingForRescue;
}


bool APiece::isPieceAvailable() {
	return currentMovePoint != 0;
}

void APiece::initializePieceState() {
	resetCurrentMovePoint();
	resetCurrentEnergyPoint();
	resetTemporaryStatus();
}

void APiece::updatePieceState() {
	resetCurrentMovePoint();
	applyAllStatus();
}


void APiece::getKilled(APiece*& killerPiece) {
	UPower* killerPower = killerPiece->getPowerBelong();

	powerBelong->updateRelation(killerPower->getPowerName(), -1);
	killerPower->updateRelation(powerBelong->getPowerName(), -1);
}


/*for player control*/
void APiece::receiveCommand(FLocation targetLocation, UBoard*& missionBoard,
	UBoard*& revealedBoard) {
	/*depends on the last ability used type*/
	switch (lastUsedAbility) {
		case EAbilitySelected::ENone: {
			break;
		}
		case EAbilitySelected::EDefault: {
			selectDefaultAbility(targetLocation, missionBoard, revealedBoard);
			break;
		}
		case EAbilitySelected::EOne: {
			selectAbilityOne(targetLocation, missionBoard, revealedBoard);
			break;
		}
		case EAbilitySelected::ETwo: {
			selectAbilityTwo(targetLocation, missionBoard, revealedBoard);
			break;
		}
	}
}

/*for ai control*/
void APiece::calculateInBoardValues(UBoard*& missionBoard, UBoard*& revealedBoard) {
	return; /*to implement*/
}


/*each ability just turn square to available*/
void APiece::selectDefaultAbility(FLocation targetLocation, UBoard*& missionBoard,
	UBoard*& revealedBoard) {
	APiece* tempPointer = this;
	defaultAbility->activate(tempPointer, targetLocation, missionBoard, revealedBoard);
}

void APiece::selectAbilityOne(FLocation targetLocation, UBoard*& missionBoard,
	UBoard*& revealedBoard) {
	APiece* tempPointer = this;
	abilityOne->activate(tempPointer, targetLocation, missionBoard, revealedBoard);
}

void APiece::selectAbilityTwo(FLocation targetLocation, UBoard*& missionBoard,
	UBoard*& revealedBoard) {
	APiece* tempPointer = this;
	abilityTwo->activate(tempPointer, targetLocation, missionBoard, revealedBoard);
}


void APiece::setIsAbilityCanBeSelected(bool aState) {
	return;
}