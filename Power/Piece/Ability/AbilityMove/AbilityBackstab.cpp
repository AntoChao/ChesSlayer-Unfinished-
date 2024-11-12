// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityBackstab.h"

UAbilityBackstab::UAbilityBackstab() {

}

void UAbilityBackstab::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	for (int y = -abilityDistance; y <= abilityDistance; ++y) {
		for (int x = -abilityDistance; x <= abilityDistance; ++x) {
			if (x != 0 && y != 0) {
				FLocation targetLocation = pieceLocation.add(FLocation(x, y));
				missionBoard->setBoardSquareReachable(targetLocation);
			}
		}
	}
}

void UAbilityBackstab::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	isTargetChecked = true;
	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	ABoardSquare* squareToMove = missionBoard->getBoardSquareAtLocation(targetLocation);
	
	setAbilityDirection(pieceLocation, targetLocation);

	if (squareToMove) {
		bool killed = false;
		if (squareToMove->getIsOccupied()) {
			killed = true;
		}

		squareToMove->setIsOccupied(missionBoard, owner);
		owner->updateFogOfWar(revealedBoard);
		missionBoard->resetBoardSquareReachability();

			// should add some delay into it
		if (killed) {
			abilityXDirection = getReverseDirection(abilityXDirection);
			abilityYDirection = getReverseDirection(abilityYDirection);
			FLocation evadeLocation = getNewLocationByDirection(targetLocation, specificAbilityDistance);

			squareToMove = missionBoard->getBoardSquareAtLocation(evadeLocation);
			
			squareToMove->setIsOccupied(missionBoard, owner);
			owner->updateFogOfWar(revealedBoard);
			missionBoard->resetBoardSquareReachability();
		}
	}
}