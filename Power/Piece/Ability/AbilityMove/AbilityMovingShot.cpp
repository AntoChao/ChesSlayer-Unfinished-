// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityMovingShot.h"

UAbilityMovingShot::UAbilityMovingShot() {

}

void UAbilityMovingShot::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	killedPeople = false;

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	if (moveSection) {
		for (int y = -abilityDistance; y <= abilityDistance; ++y) {
			for (int x = -abilityDistance; x <= abilityDistance; ++x) {
				if (x == 0 || y == 0) {
					FLocation targetLocation = pieceLocation.add(FLocation(x, y));
					missionBoard->setBoardSquareReachable(targetLocation);
				}
			}
		}
	}
	else {
		if (shootSection) {
			// logic not correct, because it should mark 2 squares together, like no separatable
			for (int y = -specificAbilityDistance; y <= specificAbilityDistance; ++y) {
				for (int x = -specificAbilityDistance; x <= specificAbilityDistance; ++x) {
					if (x == 0 || y == 0) {
						FLocation targetLocation = pieceLocation.add(FLocation(x, y));
						missionBoard->setBoardSquareReachable(targetLocation);
					}
				}
			}
		}
	}
}

void UAbilityMovingShot::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {

	ABoardSquare* squareToMove = missionBoard->getBoardSquareAtLocation(targetLocation);

	if (moveSection) {
		// responde move target
		if (squareToMove) {
			squareToMove->setIsOccupied(missionBoard, owner);
		}
		moveSection = false;
		shootSection = true; 
		killedPeople = false;

	}
	else {
		if (shootSection) {
			// respond shooting process
			isTargetChecked = true;
			
			// WRONG, SHOULD CHECK ALL SQUARES STILL OWNER PIECE AND NO 1 PIECE
			if (squareToMove && squareToMove->getIsOccupied()) {
				APiece* targetPiece = squareToMove->getOccupiedPiece();
				if (targetPiece) {
					targetPiece->getKilled(owner);
					killedPeople = true;
				}
			}

			moveSection = true;
			shootSection = false;
		}
	}
	owner->updateFogOfWar(revealedBoard);
	missionBoard->resetBoardSquareReachability();
}

bool UAbilityMovingShot::isAbilityAvailable(APiece*& owner) {
	return (owner->getCurrentMovePoint() >= movePointCost &&
		owner->getCurrentEnergyPoint() >= energyCost) || killedPeople;
}

void UAbilityMovingShot::abilityFinishedEffect(APiece*& owner) {
	UPieceAbilityMove::abilityFinishedEffect(owner);
}