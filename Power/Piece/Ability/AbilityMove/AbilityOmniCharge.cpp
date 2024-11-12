// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityOmniCharge.h"

UAbilityOmniCharge::UAbilityOmniCharge() {

}

void UAbilityOmniCharge::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* squareToCheck = nullptr;

	for (int i = 0; i < missionBoard->getBoardHeight(); i++) {
		for (int j = 0; j < missionBoard->getBoardWidth(); j++) {
			if (FMath::Abs(i) == FMath::Abs(j) && i != 0 && j != 0) {
				FLocation checkLocation = pieceLocation.add(FLocation(i, j));
				squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
				if (squareToCheck && squareToCheck->getIsRevealed()) {
					missionBoard->setBoardSquareReachable(checkLocation);
				}
			}
		}
	}
}