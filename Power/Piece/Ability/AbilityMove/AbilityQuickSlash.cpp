// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityQuickSlash.h"

UAbilityQuickSlash::UAbilityQuickSlash() {

}

void UAbilityQuickSlash::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* squareToCheck = nullptr;

	// axis move in 3
	for (int i = -abilityDistance; i < abilityDistance; i++) {
		for (int j = -abilityDistance; j < abilityDistance; j++) {
			if (i == 0 || j == 0) {
				if (i != 0 && j != 0) {
					FLocation checkLocation = pieceLocation.add(FLocation(i, j));
					squareToCheck = missionBoard->getBoardSquareAtLocation(checkLocation);
					
					if (squareToCheck) {
						missionBoard->setBoardSquareReachable(checkLocation);
					}
				}
			}
		}
	}

	// check omni surronder 
	for (int i = -specificAbilityDistance; i < specificAbilityDistance; i++) {
		for (int j = -specificAbilityDistance; j < specificAbilityDistance; j++) {
			if (FMath::Abs(i) + FMath::Abs(j) == 2) {
				if (i != 0 && j != 0) {
					FLocation checkLocation = pieceLocation.add(FLocation(i, j));
					squareToCheck = missionBoard->getBoardSquareAtLocation(checkLocation);

					if (squareToCheck && squareToCheck->getIsOccupied()) {
						missionBoard->setBoardSquareReachable(checkLocation);
					}
				}
			}
		}
	}
}