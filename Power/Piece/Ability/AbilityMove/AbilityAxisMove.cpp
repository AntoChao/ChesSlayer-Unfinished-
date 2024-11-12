// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityAxisMove.h"

UAbilityAxisMove::UAbilityAxisMove() {

}

void UAbilityAxisMove::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	for (int y = -abilityDistance; y <= abilityDistance; ++y) {
		for (int x = -abilityDistance; x <= abilityDistance; ++x) {
			if (FMath::Abs(x) + FMath::Abs(y) == abilityDistance) {
				FLocation targetLocation = pieceLocation.add(FLocation(x, y));
				missionBoard->setBoardSquareReachable(targetLocation);
			}
		}
	}
}