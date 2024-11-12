// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoardSquare.h"

// piece 
#include "../../Power/Piece/Piece.h"

ABoardSquare::ABoardSquare() {
	// Create and set the root scene component
	squareScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	RootComponent = squareScene;

	// Create and attach the static mesh component
	squareBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoardBody"));
	squareBody->SetupAttachment(squareScene);

	// initialize values
	canBeReached = false;
	isRevealed = false;
	isOccupied = false;
	occupiedPiece = nullptr;
	squareValue = 0;
}

void ABoardSquare::setInBoardLocation(int x, int y) {
	inBoardLocation = FLocation(x, y);
	SetActorLocation(FVector(x * sideSize / 2, y * sideSize / 2, height));
}

FLocation ABoardSquare::getInBoardLocation() {
	return inBoardLocation;
}


void ABoardSquare::setSideSize(int aValue) {
	sideSize = aValue;
}

int ABoardSquare::getSideSize() {
	return sideSize;
}


void ABoardSquare::setIsAccessible(bool squareAccessState) {
	isAccessible = squareAccessState;
}

bool ABoardSquare::getIsAccessible() {
	return isAccessible;
}


void ABoardSquare::setCanBeReached(bool reachable) {
	canBeReached = reachable;

	if (reachable) {
		canReachedEffect();
	}
	else {
		canNotReachedEffect();
	}
}

bool ABoardSquare::getCanBeReached() {
	return canBeReached;
}

void ABoardSquare::canNotReachedEffect() {
	return;
}

void ABoardSquare::canReachedEffect() {
	return;
}


void ABoardSquare::setIsRevealed(bool squareRevealState) {
	isRevealed = squareRevealState;
}

bool ABoardSquare::getIsRevealed() {
	return isRevealed;
}


void ABoardSquare::setIsOccupied(UBoard* missionBoard, APiece* aNewPiece) {
	if (isAccessible) {
		// kill effect
		if (isOccupied) {
			if (aNewPiece != nullptr) {
				occupiedPiece->getKilled(aNewPiece);
			}
		}
		occupiedEffect(aNewPiece);
	}
	else {
		// some ability does not differ unaccessible square
		ABoardSquare* nearByAccessibleSquare = missionBoard->getNearBySquare(inBoardLocation);
		nearByAccessibleSquare->setIsOccupied(missionBoard, aNewPiece);
	}
}

bool ABoardSquare::getIsOccupied() {
	return isOccupied;
}

APiece*& ABoardSquare::getOccupiedPiece() {
	return occupiedPiece;
}

void ABoardSquare::occupiedEffect(APiece* aNewPiece) {
	isOccupied = (aNewPiece != nullptr);
	occupiedPiece = aNewPiece;
	aNewPiece->setPieceSquare(this);
}

void ABoardSquare::swapOccupiedPieces(ABoardSquare* anotherSquare) {
	APiece* targetPiece = anotherSquare->getOccupiedPiece();

	// avoid the kill effect
	anotherSquare->occupiedEffect(this->occupiedPiece);
	this->occupiedEffect(targetPiece);
}


void ABoardSquare::setSquareValue(int aValue) {
	squareValue = aValue;
}

int ABoardSquare::getSquareValue() {
	return squareValue;
}

void ABoardSquare::updateSquareValue(int modifier) {
	squareValue += modifier;
}
