// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityRush.h"

UAbilityRush::UAbilityRush() {

}

void UAbilityRush::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* squareToCheck = nullptr;

	// add logic such as can not leap through mountain...etc
	for (int i = -abilityDistance; i < abilityDistance; i++) {
		for (int j = -abilityDistance; j < abilityDistance; j++) {
			if (i == 0 || j == 0) {
				if (FMath::Abs(i) + FMath::Abs(j) == abilityDistance) {
					
					FLocation checkLocation = pieceLocation.add(FLocation(i, j));
					squareToCheck = missionBoard->getBoardSquareAtLocation(checkLocation);

					if (squareToCheck && !squareToCheck->getIsOccupied()) {
						missionBoard->setBoardSquareReachable(checkLocation);
					}
					
				}
			}
		}
	}
}

void UAbilityRush::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {

	isTargetChecked = true;

	// know the leap direction
	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	setAbilityDirection(pieceLocation, targetLocation);

	// find the closer collided piece
	APiece* passingByPiece = nullptr;

	int modifier = 1;

	if (abilityXDirection != EAbilityDirection::ENone) {
		if (abilityXDirection == EAbilityDirection::ELeft) {
			modifier = -1;
		}
		else {
			modifier = 1;
		}
		for (int i = 1; i < abilityDistance; i += modifier) {
			FLocation checkLocation = pieceLocation.add(FLocation(i * modifier, 0));
			ABoardSquare* checkedSquare = missionBoard->getBoardSquareAtLocation(checkLocation);
			if (checkedSquare && checkedSquare->getIsOccupied() && checkedSquare->getIsAccessible()) {
				passingByPiece = checkedSquare->getOccupiedPiece();
				if (passingByPiece) {
					passingByPiece->getKilled(owner);
				}
			}
		}
	}
	else {
		if (abilityYDirection != EAbilityDirection::ENone) {
			if (abilityYDirection == EAbilityDirection::EUp) {
				modifier = -1;
			}
			else {
				modifier = 1;
			}
		}
		for (int i = 1; i < abilityDistance; i += modifier) {
			FLocation checkLocation = pieceLocation.add(FLocation(0, i * modifier));
			ABoardSquare* checkedSquare = missionBoard->getBoardSquareAtLocation(checkLocation);
			if (checkedSquare && checkedSquare->getIsOccupied() && checkedSquare->getIsAccessible()) {
				passingByPiece = checkedSquare->getOccupiedPiece();
				if (passingByPiece) {
					passingByPiece->getKilled(owner);
				}
			}
		}
	}

	ABoardSquare* squareToMove = missionBoard->getBoardSquareAtLocation(targetLocation);
	if (squareToMove) {
		squareToMove->setIsOccupied(missionBoard, owner);
		owner->updateFogOfWar(revealedBoard);
		missionBoard->resetBoardSquareReachability();
	}
}