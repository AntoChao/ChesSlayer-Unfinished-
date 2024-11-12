// Copyright Epic Games, Inc. All Rights Reserved.

#include "Board.h"

UBoard::UBoard() {
	// Create and set the root scene component

}

void UBoard::setBoardSize(int height, int width) {
	numRow = height;
	numColumn = width;
}

int UBoard::getBoardHeight() {
	return numRow;
}

int UBoard::getBoardWidth() {
	return numColumn;
}

TArray<ABoardSquare*>& UBoard::getAllSquares() {
	return allBoardSquares;
}

void UBoard::addSquare(ABoardSquare* aSquare) {
	allBoardSquares.Add(aSquare);
}

// board square
	// potential error, need to valid location before
ABoardSquare*& UBoard::getBoardSquareAtLocation(FLocation aLocation) {
	int index = numColumn * aLocation.y + aLocation.x;
	if (index < allBoardSquares.Num()) {
		return allBoardSquares[index];
	}
	else {
		return allBoardSquares[0];
	}
}

bool UBoard::isBoardSquareValid(FLocation aLocation) {
	return aLocation.x >= 0 && aLocation.x < numRow&&
		aLocation.y >= 0 && aLocation.y < numColumn;
}

void UBoard::setBoardSquareReachable(FLocation targetLocation) {
	if (isBoardSquareValidToMove(targetLocation)) {
		ABoardSquare* targetSquare = this->getBoardSquareAtLocation(targetLocation);
		targetSquare->setCanBeReached(true);
	}
}

void UBoard::setBoardSquareReachableNotChecking(FLocation targetLocation) {
	ABoardSquare* targetSquare = this->getBoardSquareAtLocation(targetLocation);
	targetSquare->setCanBeReached(true);
}

bool UBoard::isBoardSquareValidToMove(FLocation aLocation) {
	return isBoardSquareValid(aLocation) &&
		getBoardSquareAtLocation(aLocation)->getIsAccessible();
}

// ensure that the nearby square is valid (not have to be accessible)
ABoardSquare*& UBoard::getNearBySquare(FLocation aLocation) {
	FLocation nearbyLocation = aLocation.add(FLocation(FMath::RandRange(-1, 1), FMath::RandRange(-1, 1)));

	while (!isBoardSquareValid(nearbyLocation)) {
		nearbyLocation = aLocation.add(FLocation(FMath::RandRange(-1, 1), FMath::RandRange(-1, 1)));
	}
	
	return getBoardSquareAtLocation(nearbyLocation);
}


// piece
void UBoard::getAllSamePowerPieces(TArray<APiece*>& samePowerPieces, APiece*& onePiece) {
	TArray<APiece*> tempSamePowerPieces = {};

	if (onePiece) {
		for (ABoardSquare* eachBoardSquare : allBoardSquares) {
			if (eachBoardSquare && eachBoardSquare->getIsOccupied()) {
				APiece* pieceToCheck = eachBoardSquare->getOccupiedPiece();
				if (pieceToCheck && onePiece->isSamePower(pieceToCheck) && onePiece != pieceToCheck) {
					tempSamePowerPieces.Add(pieceToCheck);
				}
			}
		}
	}
	
	samePowerPieces = tempSamePowerPieces;
}


APiece* UBoard::getRandomPieceOnBoard() {
	TArray<APiece*> allBoardPieces;
	for (ABoardSquare* eachSquare : allBoardSquares) {
		if (eachSquare->getIsOccupied()) {
			APiece* inBoardPiece = eachSquare->getOccupiedPiece();
			if (inBoardPiece) {
				allBoardPieces.Add(inBoardPiece);
			}
		}
	}

	return allBoardPieces[FMath::RandRange(0, allBoardPieces.Num() - 1)];
}


void UBoard::pushPieceXDistance(FLocation initLocation, EAbilityDirection toPushDirection,
	int specificAbilityDistance) {
	APiece* targetPiece = getBoardSquareAtLocation(initLocation)->getOccupiedPiece();

	if (targetPiece) {
		for (int i = 0; i < specificAbilityDistance; i++) {
			// true if collided with something meaning it should stop
			if (pushPiece(initLocation, toPushDirection)) {
				break; /*get out of the loop for no more pushing*/
			}
		}
	}
}

bool UBoard::pushPiece(FLocation initLocation, EAbilityDirection toPushDirection) {
	
	APiece* pushedPiece = getBoardSquareAtLocation(initLocation)->getOccupiedPiece();

	FLocation normalDirection = getRelativeDirection(toPushDirection);
	FLocation targetLocation = initLocation.add(normalDirection);

	bool collided = false;
	ABoardSquare* targetSquare = getBoardSquareAtLocation(targetLocation);
	if (targetSquare && targetSquare->getIsOccupied()) {
		collided = true;
	}
	targetSquare->setIsOccupied(this, pushedPiece);

	return collided;
}

FLocation UBoard::getRelativeDirection(EAbilityDirection aDirection) {
	FLocation targetDirection = FLocation(0, 0);
	switch (aDirection) {
	case EAbilityDirection::ENone: {
			targetDirection = FLocation(0, 0);
			break;
		}
	case EAbilityDirection::EUpLeft:{
			targetDirection = FLocation(-1, -1);
			break;
		}
	case EAbilityDirection::EUp: {
			targetDirection = FLocation(0, -1);
			break;
		}
	case EAbilityDirection::EUpRight: {
			targetDirection = FLocation(1, -1);
			break;
		}
	case EAbilityDirection::ERight: {
			targetDirection = FLocation(1, 0);
			break;
		}
	case EAbilityDirection::EDownRight: {
			targetDirection = FLocation(1, 1);
			break;
		}
	case EAbilityDirection::EDown: {
			targetDirection = FLocation(0, 1);
			break;
		}
	case EAbilityDirection::EDownLeft: {
			targetDirection = FLocation(-1, 1);
			break;
		}
	case EAbilityDirection::ELeft: {
			targetDirection = FLocation(-1, 0);
			break;
		}
	}
	return targetDirection;
}


// reachability
void UBoard::setBoardSquareReachability(FLocation aLocation) {
	if (aLocation.y != 0) {
		aLocation.y--;
	}

	int index = numColumn * aLocation.y + aLocation.x;
	allBoardSquares[index]->setCanBeReached(true);
}

void UBoard::resetBoardSquareReachability() {
	for (ABoardSquare* eachSquare : allBoardSquares) {
		eachSquare->setCanBeReached(false);
	}
}


// value
void UBoard::setBoardSquareValue(FLocation aLocation, int aValue) {
	if (aLocation.y != 0) {
		aLocation.y--;
	}

	int index = numColumn * aLocation.y + aLocation.x;
	allBoardSquares[index]->setSquareValue(aValue);
}

void UBoard::resetBoardSquareValues() {
	for (ABoardSquare* eachSquare : allBoardSquares) {
		eachSquare->setSquareValue(0);
	}
}