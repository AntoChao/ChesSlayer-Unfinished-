// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityHunt.h"

UAbilityHunt::UAbilityHunt() {

}

void UAbilityHunt::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	if (targetPiece == nullptr) {
		// this turn the ability is to select and mark an enemy piece
		while (targetPiece == nullptr || owner->isEnemyPower(targetPiece)) {
			targetPiece = missionBoard->getRandomPieceOnBoard();
		}
		// add a mark status
		targetPiece->addStatus(nullptr);

	}
	else {
		isSelected = true;

		// reset all values
		resetAllDirectionVariables();

		TArray<FLocation> allyLocations;
		FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

		// detect target location
		FLocation targetLocation = targetPiece->getPieceSquare()->getInBoardLocation();
		FLocation difDistance = targetLocation.subtract(pieceLocation);
		
		if (FMath::Abs(difDistance.x) > FMath::Abs(difDistance.y)) {
			// target in left or right
			checkIfTargetOnHorizontal(pieceLocation, targetLocation);
		}
		else {
			if (FMath::Abs(difDistance.x) < FMath::Abs(difDistance.y)) {
				// target in up or down
				checkIfTargetOnVertical(pieceLocation, targetLocation);
			}
			else {
				// target in diagonal
				checkIfTargetOnHorizontal(pieceLocation, targetLocation);
				checkIfTargetOnVertical(pieceLocation, targetLocation);
			}
		}

		// set the distances
		setAllDirectionDistance();

		// set all reachable
		for (int y = -upDistance; y <= downDistance; ++y) {
			for (int x = -leftDistance; x <= rightDistance; ++x) {
				if (x != 0 && y != 0) {
					targetLocation = pieceLocation.add(FLocation(x, y));
					missionBoard->setBoardSquareReachable(targetLocation);
				}
			}
		}
	}
}