// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityHelpingHand.h"

UAbilityHelpingHand::UAbilityHelpingHand() {

}

void UAbilityHelpingHand::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	// reset all values
	resetAllDirectionVariables();

	TArray<FLocation> allyLocations;
	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	// detect same power pieces
	for (int y = -helpingHandDetectDistance; y <= helpingHandDetectDistance; ++y) {
		for (int x = -helpingHandDetectDistance; x <= helpingHandDetectDistance; ++x) {
			if (x != 0 && y != 0) {
				FLocation targetLocation = pieceLocation.add(FLocation(x, y));
				ABoardSquare* currenSquare = missionBoard->getBoardSquareAtLocation(targetLocation);
				if (currenSquare->getIsOccupied()) {
					APiece* currentPiece = currenSquare->getOccupiedPiece();
					if (currentPiece && owner->isSamePower(currentPiece)) {
						allyLocations.Add(targetLocation);
					}
				}
			}
		}
	}

	// detect all ally directions
	for (FLocation eachTargetLocation : allyLocations) {
		FLocation difDistance = eachTargetLocation.subtract(pieceLocation);

		if (FMath::Abs(difDistance.x) > FMath::Abs(difDistance.y)) {
			// ally in left or right
			checkIfTargetOnHorizontal(pieceLocation, eachTargetLocation);
		}
		else {
			if (FMath::Abs(difDistance.x) < FMath::Abs(difDistance.y)) {
				// ally in up or down
				checkIfTargetOnVertical(pieceLocation, eachTargetLocation);
			}
			else {
				// ally in diagonal
				checkIfTargetOnHorizontal(pieceLocation, eachTargetLocation);
				checkIfTargetOnVertical(pieceLocation, eachTargetLocation);
			}
		}
	}

	// set the distances
	setAllDirectionDistance();

	// set all reachable
	for (int y = -upDistance; y <= downDistance; ++y) {
		for (int x = -leftDistance; x <= rightDistance; ++x) {
			if (x != 0 && y != 0) {
				FLocation targetLocation = pieceLocation.add(FLocation(x, y));
				missionBoard->setBoardSquareReachable(targetLocation);
			}
		}
	}
}