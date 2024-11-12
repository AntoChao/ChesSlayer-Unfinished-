// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilitySheldPush.h"

UAbilitySheldPush::UAbilitySheldPush() {

}

void UAbilitySheldPush::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* checkSquare = nullptr;

	// check up squares
	for (int i = 0; i <= abilityDistance; i++) {
		FLocation targetLocation = pieceLocation.add(FLocation(0, -i));
		checkSquare = missionBoard->getBoardSquareAtLocation(targetLocation);

		if (checkSquare && !checkSquare->getIsOccupied()) {
			missionBoard->setBoardSquareReachable(targetLocation);
		}
		else {
			break;
		}
	}

	// check down squares
	for (int i = 0; i <= abilityDistance; i++) {
		FLocation targetLocation = pieceLocation.add(FLocation(0, i));
		checkSquare = missionBoard->getBoardSquareAtLocation(targetLocation);

		if (checkSquare && !checkSquare->getIsOccupied()) {
			missionBoard->setBoardSquareReachable(targetLocation);
		}
		else {
			break;
		}
	}

	// check left squares
	for (int i = 0; i <= abilityDistance; i++) {
		FLocation targetLocation = pieceLocation.add(FLocation(-i, 0));
		checkSquare = missionBoard->getBoardSquareAtLocation(targetLocation);

		if (checkSquare && !checkSquare->getIsOccupied()) {
			missionBoard->setBoardSquareReachable(targetLocation);
		}
		else {
			break;
		}
	}

	// check right squares
	for (int i = 0; i <= abilityDistance; i++) {
		FLocation targetLocation = pieceLocation.add(FLocation(i, 0));
		checkSquare = missionBoard->getBoardSquareAtLocation(targetLocation);

		if (checkSquare && !checkSquare->getIsOccupied()) {
			missionBoard->setBoardSquareReachable(targetLocation);
		}
		else {
			break;
		}
	}
}

void UAbilitySheldPush::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	isTargetChecked = true;

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* targetSquare = missionBoard->getBoardSquareAtLocation(targetLocation);
	
	// check if kill any piece
	if (targetSquare) {
		if (targetSquare->getIsOccupied()) {
			// kill an piece
			targetSquare->setIsOccupied(missionBoard, owner);
		}
		else {
			// push omni surronding pieces
			for (int i = -specificAbilityDistance; i < specificAbilityDistance; i++) {
				for (int j = -specificAbilityDistance; j < specificAbilityDistance; j++) {
					FLocation targetLocation = pieceLocation.add(FLocation(i, j));
					targetSquare = missionBoard->getBoardSquareAtLocation(targetLocation);
					if (targetSquare && targetSquare->getIsOccupied()) {
						setAbilityDirection(pieceLocation, targetLocation);
						EAbilityDirection toPushDirection = getOmniDirection();

						missionBoard->pushPieceXDistance(targetLocation, toPushDirection, 
							specificAbilityDistance);
					}
				}
			}
		
		}
	}
	owner->updateFogOfWar(revealedBoard);
	missionBoard->resetBoardSquareReachability();
}