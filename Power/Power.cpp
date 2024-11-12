// Copyright Epic Games, Inc. All Rights Reserved.

#include "Power.h"
#include "Math/UnrealMathUtility.h"
#include <limits.h>

// piece
#include "Piece/Piece.h"

// mission
#include "../Stage/CSMission.h"

UPower::UPower() {
	// initialize the piece generator
	
	// add noises to relationships
	initPlayerRelation = getNoisedValue(initPlayerRelation, initRelationNoise);
	initEmpireRelation = getNoisedValue(initEmpireRelation, initRelationNoise);
	initBanditRelation = getNoisedValue(initBanditRelation, initRelationNoise);
	initForeigerRelation = getNoisedValue(initForeigerRelation, initRelationNoise);
}

void UPower::InitPower(int aDifficulty, int currentStage, TArray<APiece*> selectedPieces) {
	return;
}

// common methods
int UPower::getNoisedValue(int value, int noise) {
	return FMath::RandRange(value - noise, value + noise);
}

EPowerName UPower::getPowerName() {
	return powerName;
}

// army methods
void UPower::setMaxArmyEnergy(int difficulty, int currentStage) {
}

void UPower::updateMaxArmyEnergy(int modifier) {
	armyMaxEnergy += modifier;
}

void UPower::calculateRemaningArmyEnergy() {
	armyRemainingEnergy = armyMaxEnergy - currentArmyEnergy;
}

void UPower::updateCurrentAmryEnergy(int modifier) {
	currentArmyEnergy += modifier;
}

int UPower::getArmyMaxEnergy() {
	return armyMaxEnergy;
}

int UPower::getArmyCurrentEnergy() {
	return currentArmyEnergy;
}

// army method by army fnames
void UPower::initializeArmyPiecesByName() {
	army = {};
	for (FName eachPieceName : armyNames) {
		APiece* aPieceToAdd = recruitSpecificPieceByName(eachPieceName);
		if (isAbleToAddPiece(aPieceToAdd)) {
			addArmyPiece(aPieceToAdd);
		}
	}
}

void UPower::saveArmyPiecesInName() {
	for (APiece* aPiece : army) {
		armyNames.Add(aPiece->getPieceName());
	}
}

// army method with pieces
bool UPower::isAbleToAddPiece(APiece* pieceToAdd) {
	int pieceEnergy = pieceToAdd->getEnergyPoint();
	return armyRemainingEnergy - pieceEnergy >= 0;
}

void UPower::fillArmyByRandom() {
	APiece* randomPiece = recruitRandomPiece();
	while (isAbleToAddPiece(randomPiece)) {
		addArmyPiece(randomPiece);
		randomPiece = recruitRandomPiece();
	}
	selectLeader();
}

TArray<APiece*> UPower::getArmy() {
	return army;
}

void UPower::addArmyPiece(APiece*& newPiece) {
	updateCurrentAmryEnergy(newPiece->getEnergyPoint());
	calculateRemaningArmyEnergy();
	army.Add(newPiece);
}

void UPower::removeArmyPiece(APiece*& pieceToRemove) {
	updateCurrentAmryEnergy(-pieceToRemove->getEnergyPoint());
	calculateRemaningArmyEnergy();
	army.Remove(pieceToRemove);
}

APiece* UPower::recruitSpecificPieceByName(FName pieceName) {
	APiece* generatedPiece = nullptr;

	UPieceGenerator* pieceGenerator = UPieceGenerator::GetPieceGeneratorInstance();
	if (pieceGenerator){
		generatedPiece = pieceGenerator->generateSpecificPieceByName(GetWorld(), pieceName);
	}

	return generatedPiece;
}
APiece* UPower::recruitRandomPiece() {
	APiece* generatedPiece = nullptr;
	
	UPieceGenerator* pieceGenerator = UPieceGenerator::GetPieceGeneratorInstance();

	if (pieceGenerator) {
		switch (powerName) {
			case EPowerName::EPlayer:
				generatedPiece = pieceGenerator->generateRandomPiece(GetWorld());
			case EPowerName::EEmpire:
				generatedPiece = pieceGenerator->generateEmpirePiece(GetWorld());
			case EPowerName::EBandit:
				generatedPiece = pieceGenerator->generateBanditPiece(GetWorld());
			case EPowerName::EForeiger:
				generatedPiece = pieceGenerator->generateForeigerPiece(GetWorld());
			default:
				generatedPiece = nullptr;
		}
	}
	UPower* thisPower = this;
	generatedPiece->initPiece(thisPower);

	return generatedPiece;
}

void UPower::selectLeader() {
	APiece* maxEnergyPiece = army[0];
	int maxEnergy = army[0]->getEnergyPoint();
	
	if (armyLeader) {
		armyLeader->setIsArmyLeader(false);
	}

	int curEnergy = -999;
	for (APiece* eachPiece : army) {
		curEnergy = eachPiece->getEnergyPoint();
		if (curEnergy > maxEnergy) {
			maxEnergy = curEnergy;
			maxEnergyPiece = eachPiece;
		}
	}
	armyLeader = maxEnergyPiece;
	armyLeader->setIsArmyLeader(true);

}

APiece* UPower::getArmyLeader() {
	return armyLeader;
}

// relationship methods
void UPower::initializeRelationship() {
	relationships = CreateDefaultSubobject<URelationship>(TEXT("Power Relationship"));

	if (relationships) {
		relationships->setRelationWithPlayer(initPlayerRelation);
		relationships->setRelationWithEmpire(initEmpireRelation);
		relationships->setRelationWithBandit(initBanditRelation);
		relationships->setRelationWithForeiger(initForeigerRelation);
	}
}

URelationship* UPower::getRelationship() {
	return relationships;
}


void UPower::updateRelation(EPowerName thePowerName, int value) {
	switch (thePowerName) {
		case EPowerName::EPlayer :
			relationships->updateRelationWithPlayer(value);
			break;
		case EPowerName::EEmpire:
			relationships->updateRelationWithEmpire(value);
			break;
		case EPowerName::EBandit:
			relationships->updateRelationWithBandit(value);
			break;
		case EPowerName::EForeiger:
			relationships->updateRelationWithForeiger(value);
			break;
		default:
			break;
	}
}


//mission method
void UPower::setRevealedBoard(UBoard* currentBoard) {
	revealedBoard = currentBoard;
}

UBoard* UPower::getRevealedBoard() {
	return revealedBoard;
}


void UPower::setInitLocation(FLocation aLocation) {
	initLocation = aLocation;
}

FLocation UPower::getInitLocation() {
	return initLocation;
}

// power turn control
void UPower::locateInitPieces() {
	return;
}

bool UPower::isOkayToEndTurn() {
	return isReadyToEndTurn;
}

bool UPower::stillHaveAvailablePiece() {
	for (APiece* armyPiece : army) {
		if (armyPiece) {
			if (armyPiece->isPieceAvailable()) {
				return true;
			}
		}
	}
	return false;
}

void UPower::setIsReadyToEndTurn(bool aNewState) {
	isReadyToEndTurn = aNewState;
}

bool UPower::getIsReadyToEndTurn() {
	return isReadyToEndTurn;
}

// power turn action
void UPower::startTurn(UCSMission*& aCurrentMission) {
	currentMission = currentMission;
}

void UPower::endAction() {
	if (currentMission) {
		currentMission->powerActionFinished(powerName);
	}
}

void UPower::endTurn() {
	if (currentMission) {
		currentMission->powerTurnFinished(powerName);
		currentMission = nullptr;
		pieceMoved = nullptr;
	}
}

	// player
void UPower::reactPlayerInput(FLocation targetLocation, UBoard*& missionBoard) {
	ABoardSquare* targetSquare = missionBoard->getBoardSquareAtLocation(targetLocation);
	APiece* targetPiece = nullptr;
	if (targetSquare) {
		setCurrentInspectedSquare(targetSquare);

		// check if there is a piece on the square
		if (targetSquare->getIsOccupied() && targetSquare->getIsAccessible()) {
			targetPiece = targetSquare->getOccupiedPiece();

			if (targetPiece) {
				setCurrentInspectedPiece(targetPiece);
			}
			else {
				unsetCurrentInspectedPiece();
			}
		}
		else {
			unsetCurrentSelectedPiece();
			unsetCurrentInspectedPiece();
		}

		// is an targetSquare, meaning have selected a piece already
		if (targetSquare->getCanBeReached()) {
			if (currentSelectedPiece) {
				currentSelectedPiece->receiveCommand(targetLocation, missionBoard, revealedBoard);
				pieceMoved = currentSelectedPiece;
			}
		}
		else {
			if (targetPiece && army.Contains(targetPiece)) {
				if (pieceMoved == nullptr || pieceMoved == targetPiece) {
					setCurrentSelectedPiece(targetPiece);
				}
			}
		}
	}
	else {
		unsetCurrentInspectedSquare();
	}
}

void UPower::setCurrentSelectedPiece(APiece*& aPiece) {
	currentSelectedPiece = aPiece;
	currentSelectedPiece->setIsSelected(true);
}

void UPower::unsetCurrentSelectedPiece() {
	if (currentSelectedPiece) {
		currentSelectedPiece->setIsSelected(false);
		currentSelectedPiece = nullptr;
	}
}


void UPower::setCurrentInspectedPiece(APiece*& aPiece) {
	currentInspectedPiece = aPiece;
}

void UPower::unsetCurrentInspectedPiece() {
	if (currentInspectedPiece) {
		currentInspectedPiece = nullptr;
	}
}


void UPower::setCurrentInspectedSquare(ABoardSquare* aSquare) {
	currentInspectedSquare = aSquare;
}

void UPower::unsetCurrentInspectedSquare() {
	if (currentInspectedSquare) {
		currentInspectedSquare = nullptr;
	}
}
	// ai
void UPower::calculateAllBoardValues(FLocation targetLocation) {
	return;
}

	// piece ability selection
	/*unselect piece ability will let all board be unreachable*/
void UPower::unselectPieceAbility(UBoard*& missionBoard) {
	if (currentSelectedPiece) {
		currentSelectedPiece->setLastAbilityUsed(EAbilitySelected::ENone);
	}
	missionBoard->resetBoardSquareReachability();
}

void UPower::selectPieceDefaultAbility(FLocation targetLocation, UBoard*& missionBoard) {
	if (currentSelectedPiece) {
		currentSelectedPiece->setLastAbilityUsed(EAbilitySelected::EDefault);
		currentSelectedPiece->selectDefaultAbility(targetLocation, missionBoard, revealedBoard);
	}
}

void UPower::selectPieceAbilityOne(FLocation targetLocation, UBoard*& missionBoard) {
	if (currentSelectedPiece) {
		currentSelectedPiece->setLastAbilityUsed(EAbilitySelected::EOne);
		currentSelectedPiece->selectAbilityOne(targetLocation, missionBoard, revealedBoard);
	}
}

void UPower::selectPieceAbilityTwo(FLocation targetLocation, UBoard*& missionBoard) {
	if (currentSelectedPiece) {
		currentSelectedPiece->setLastAbilityUsed(EAbilitySelected::ETwo);
		currentSelectedPiece->selectAbilityTwo(targetLocation, missionBoard, revealedBoard);
	}
}


// power end function
void UPower::missionEndEffect() {
	updateArmyAfterMission();
}

// update for ai only
void UPower::updateArmyAfterMission() {
	fillArmyByRandom();
}