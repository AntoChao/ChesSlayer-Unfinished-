// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityOmniMove.h"

UAbilityOmniMove::UAbilityOmniMove() {

}

void UAbilityOmniMove::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	
		// ability distance should be 1
	for (int i = -abilityDistance; i < abilityDistance; i++) {
		for (int j = -abilityDistance; j < abilityDistance; j++) {
			if (i != 0 && j != 0) {
				FLocation checkLocation = pieceLocation.add(FLocation(i, j));
				missionBoard->setBoardSquareReachable(checkLocation);
			}
		}
	}
}
