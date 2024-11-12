// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityPortal.h"

UAbilityPortal::UAbilityPortal() {

}

void UAbilityPortal::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	// detection radius -> whole map
	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* squareToCheck = nullptr;

	for (int i = 0; i < missionBoard->getBoardHeight(); i++) {
		for (int j = 0; j < missionBoard->getBoardWidth(); j++) {
			FLocation checkLocation = FLocation(i, j);
			squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
			if (squareToCheck && squareToCheck->getIsRevealed()) {
				squareToCheck = missionBoard->getBoardSquareAtLocation(checkLocation);
				
				// for now it accept all pieces, no matter powers
				if (squareToCheck && squareToCheck->getIsOccupied()) {
					missionBoard->setBoardSquareReachable(checkLocation);
				}
			}
		}
	}
}

void UAbilityPortal::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isTargetCheckedEffect(owner, targetLocation, missionBoard, revealedBoard);

	isTargetChecked = true;

	// sawp location
	ABoardSquare* targetSquare = missionBoard->getBoardSquareAtLocation(targetLocation);
	if (targetSquare && targetSquare->getIsOccupied()) {
		ABoardSquare* ownerSquare = owner->getPieceSquare();
		if (ownerSquare) {
			ownerSquare->swapOccupiedPieces(targetSquare);
		}
	}
}