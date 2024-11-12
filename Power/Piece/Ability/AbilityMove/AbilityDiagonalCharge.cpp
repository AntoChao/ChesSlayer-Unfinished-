// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityDiagonalCharge.h"

UAbilityDiagonalCharge::UAbilityDiagonalCharge() {

}

void UAbilityDiagonalCharge::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	for (int y = -abilityDistance; y <= abilityDistance; ++y) {
		for (int x = -abilityDistance; x <= abilityDistance; ++x) {
			if (FMath::Abs(x) == FMath::Abs(y) && (x != 0 && y != 0)) {
				FLocation targetLocation = pieceLocation.add(FLocation(x, y));
				missionBoard->setBoardSquareReachable(targetLocation);
			}
		}
	}
}
