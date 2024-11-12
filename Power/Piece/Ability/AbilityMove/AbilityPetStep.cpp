// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityPetStep.h"

UAbilityPetStep::UAbilityPetStep() {

}

void UAbilityPetStep::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	resetAllDirectionVariables();
	
	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	if (petPiece && petPiece->getIsAlive()) {
		FLocation targetLocation = petPiece->getPieceSquare()->getInBoardLocation();

		checkIfTargetOnHorizontal(pieceLocation, targetLocation);
		checkIfTargetOnVertical(pieceLocation, targetLocation);

		setAllDirectionDistance();

		for (int i = -upDistance; i < downDistance; i++) {
			for (int j = -leftDistance; j < rightDistance; j++) {
				if (i != 0 && j != 0) {
					FLocation checkLocation = pieceLocation.add(FLocation(i, j));
					missionBoard->setBoardSquareReachable(checkLocation);
				}
			}
		}
	}
	else {
		for (int i = -abilityDistance; i < abilityDistance; i++) {
			for (int j = -abilityDistance; j < abilityDistance; j++) {
				if (i != 0 && j != 0) {
					FLocation checkLocation = pieceLocation.add(FLocation(i, j));
					missionBoard->setBoardSquareReachable(checkLocation);
				}
			}
		}
	}
}

void UAbilityPetStep::setPetPiece(APiece* aPetPiece) {
	petPiece = aPetPiece;
}