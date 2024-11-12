// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityLeapingHunt.h"

UAbilityLeapingHunt::UAbilityLeapingHunt() {

}

void UAbilityLeapingHunt::isSelectedEffect(APiece*& owner, FLocation targetLocation,
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

void UAbilityLeapingHunt::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	isTargetChecked = true;

	// know the leap direction
	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	setAbilityDirection(pieceLocation, targetLocation);

	// find the closer collided piece
	FLocation collidedLocation = targetLocation;

	int modifier = 1;
	int dif = 0;
	
	if (abilityXDirection != EAbilityDirection::ENone) {
		if (abilityXDirection == EAbilityDirection::ELeft) {
			modifier = -1;
		}
		else {
			modifier = 1;
		}
		dif = FMath::Abs(pieceLocation.x - targetLocation.x);
		for (int i = 1; i <= dif; i += modifier) {
			FLocation checkLocation = pieceLocation.add(FLocation(i * modifier, 0));
			ABoardSquare* checkedSquare = missionBoard->getBoardSquareAtLocation(checkLocation);
			if (checkedSquare && checkedSquare->getIsOccupied() && checkedSquare->getIsAccessible()) {
				collidedLocation = checkLocation;
			}
		}
	}
	else {
		if (abilityYDirection != EAbilityDirection::ENone) {
			if (abilityYDirection == EAbilityDirection::EUp) {
				modifier = -1;
			}
			else {
				modifier = 1;
			}
		}
		dif = FMath::Abs(pieceLocation.y - targetLocation.y);
		for (int i = 1; i <= dif; i += modifier) {
			FLocation checkLocation = pieceLocation.add(FLocation(0, i * modifier));
			ABoardSquare* checkedSquare = missionBoard->getBoardSquareAtLocation(checkLocation);
			if (checkedSquare && checkedSquare->getIsOccupied() && checkedSquare->getIsAccessible()) {
				collidedLocation = checkLocation;
			}
		}
	}

	ABoardSquare* squareToMove = missionBoard->getBoardSquareAtLocation(collidedLocation);
	if (squareToMove) {
		squareToMove->setIsOccupied(missionBoard, owner);
		owner->updateFogOfWar(revealedBoard);
		missionBoard->resetBoardSquareReachability();
	}
}