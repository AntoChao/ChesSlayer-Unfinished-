// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityShadowStep.h"

UAbilityShadowStep::UAbilityShadowStep() {

}

void UAbilityShadowStep::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* squareToCheck = nullptr;

	for (int i = 0; i < missionBoard->getBoardHeight(); i++) {
		for (int j = 0; j < missionBoard->getBoardWidth(); j++) {
			FLocation checkLocation = FLocation(i, j);
			squareToCheck = revealedBoard->getBoardSquareAtLocation(checkLocation);
			if (squareToCheck && !squareToCheck->getIsRevealed()) {
				squareToCheck = missionBoard->getBoardSquareAtLocation(checkLocation);

				if (squareToCheck) {
					missionBoard->setBoardSquareReachableNotChecking(checkLocation);
				}
			}
		}
	}
}
