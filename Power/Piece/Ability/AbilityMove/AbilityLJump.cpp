// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityLJump.h"

UAbilityLJump::UAbilityLJump() {

}

void UAbilityLJump::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	for (int y = -2; y <= 2; ++y) {
		for (int x = -2; x <= 2; ++x) {
			if (FMath::Abs(x) + FMath::Abs(y) == 3) {
				FLocation targetLocation = pieceLocation.add(FLocation(x, y));
				missionBoard->setBoardSquareReachable(targetLocation);
			}
		}
	}
}