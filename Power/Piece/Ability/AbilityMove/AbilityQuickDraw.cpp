// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityQuickDraw.h"

UAbilityQuickDraw::UAbilityQuickDraw() {

}

void UAbilityQuickDraw::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	for (int i = -abilityDistance; i < abilityDistance; i++) {
		for (int j = -abilityDistance; j < abilityDistance; j++) {
			if (i == 0 || j == 0) {
				FLocation targetLocation = pieceLocation.add(FLocation(i, j));
				missionBoard->setBoardSquareReachable(targetLocation);
			}
		}
	}
}

void UAbilityQuickDraw::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isTargetCheckedEffect(owner, targetLocation, missionBoard, revealedBoard);


}