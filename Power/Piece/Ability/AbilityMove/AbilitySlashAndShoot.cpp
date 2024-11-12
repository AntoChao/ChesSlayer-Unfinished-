// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilitySlashAndShoot.h"

UAbilitySlashAndShoot::UAbilitySlashAndShoot() {

}

void UAbilitySlashAndShoot::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	for (int i = -abilityDistance; i < abilityDistance; i++) {
		for (int j = -abilityDistance; j < abilityDistance; j++) {
			if (FMath::Abs(i) + FMath::Abs(j) <= abilityDistance) {
				FLocation checkLocation = pieceLocation.add(FLocation(i, j));
				missionBoard->setBoardSquareReachable(checkLocation);
			}
		}
	}
}