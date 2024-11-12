// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityAxisCharge.h"

UAbilityAxisCharge::UAbilityAxisCharge() {

}

void UAbilityAxisCharge::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* squareToCheck = nullptr;

	// check all same column revealed squares
	for (int i = 0; i < missionBoard->getBoardHeight() && i != pieceLocation.y; i++) {
		FLocation checkLocation = FLocation(pieceLocation.x, i);
		squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
		if (squareToCheck) {
			if (squareToCheck->getIsRevealed()) {
				missionBoard->setBoardSquareReachable(checkLocation);
			}
		}
	}

	// check all same row revealed squares
	for (int i = 0; i < missionBoard->getBoardWidth() && i != pieceLocation.x; i++) {
		FLocation checkLocation = FLocation(i, pieceLocation.y);
		squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
		if (squareToCheck) {
			if (squareToCheck->getIsRevealed()) {
				missionBoard->setBoardSquareReachable(checkLocation);
			}
		}
	}
}