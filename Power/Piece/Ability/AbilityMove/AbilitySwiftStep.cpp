// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilitySwiftStep.h"

UAbilitySwiftStep::UAbilitySwiftStep() {

}

void UAbilitySwiftStep::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	TArray<APiece*> samePowerPieces;
	missionBoard->getAllSamePowerPieces(samePowerPieces, owner);
	
	// select all axis 1 distance of all same power pieces
	for (APiece* allyPiece : samePowerPieces) {
		FLocation allyLocation = allyPiece->getPieceSquare()->getInBoardLocation();
		
		for (int i = -abilityDistance; i < abilityDistance; i++) {
			for (int j = -abilityDistance; j < abilityDistance; j++) {
				if (FMath::Abs(i) + FMath::Abs(j) == abilityDistance) {
					FLocation targetLocation = allyLocation.add(FLocation(i, j));
					missionBoard->setBoardSquareReachable(targetLocation);
				}
			}
		}
	}

}