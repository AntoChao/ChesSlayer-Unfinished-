// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityBroomFlight.h"

UAbilityBroomFlight::UAbilityBroomFlight() {

}

void UAbilityBroomFlight::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	for (int y = -abilityDistance; y <= abilityDistance; ++y) {
		for (int x = -abilityDistance; x <= abilityDistance; ++x) {
			if (x == 0 || y == 0) {
				if (FMath::Abs(x) + FMath::Abs(y) == abilityDistance) {
					FLocation targetLocation = pieceLocation.add(FLocation(x, y));
					missionBoard->setBoardSquareReachable(targetLocation);
				}
			}
		}
	}
}
