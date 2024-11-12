// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilitySilentStrike.h"

UAbilitySilentStrike::UAbilitySilentStrike() {

}

void UAbilitySilentStrike::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	// ability distance should be 3
	for (int i = -abilityDistance; i < abilityDistance; i++) {
		for (int j = -abilityDistance; j < abilityDistance; j++) {
			if (FMath::Abs(i) == abilityDistance || FMath::Abs(j) == abilityDistance) {
				FLocation checkLocation = pieceLocation.add(FLocation(i, j));
				missionBoard->setBoardSquareReachable(checkLocation);
			}
		}
	}
}