// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityLongShot.h"

UAbilityLongShot::UAbilityLongShot() {

}

void UAbilityLongShot::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
    UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

    FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
    ABoardSquare* squareToCheck = nullptr;

    // Check all revealed squares in the same column above
    for (int i = pieceLocation.y - 1; i >= 0; i--) {
        FLocation checkLocation = FLocation(pieceLocation.x, i);
        squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
        if (squareToCheck && squareToCheck->getIsRevealed()) {
            missionBoard->setBoardSquareReachable(checkLocation);
        }
    }

    // Check all revealed squares in the same column below
    for (int i = pieceLocation.y + 1; i < missionBoard->getBoardHeight(); i++) {
        FLocation checkLocation = FLocation(pieceLocation.x, i);
        squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
        if (squareToCheck && squareToCheck->getIsRevealed()) {
            missionBoard->setBoardSquareReachable(checkLocation);
        }
    }

    // Check all revealed squares in the same row to the left
    for (int i = pieceLocation.x - 1; i >= 0; i--) {
        FLocation checkLocation = FLocation(i, pieceLocation.y);
        squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
        if (squareToCheck && squareToCheck->getIsRevealed()) {
            missionBoard->setBoardSquareReachable(checkLocation);
        }
    }

    // Check all revealed squares in the same row to the right
    for (int i = pieceLocation.x + 1; i < missionBoard->getBoardWidth(); i++) {
        FLocation checkLocation = FLocation(i, pieceLocation.y);
        squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
        if (squareToCheck && squareToCheck->getIsRevealed()) {
            missionBoard->setBoardSquareReachable(checkLocation);
        }
    }
}
