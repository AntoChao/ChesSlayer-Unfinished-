// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityMarch.h"

UAbilityMarch::UAbilityMarch() {

}

void UAbilityMarch::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);

	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();
	updateCurrentSpeed(pieceLocation, targetLocation);

	ABoardSquare* squareToCheck = nullptr;

	// only axis
	for (int y = -upDistance; y <= downDistance; ++y) {
		for (int x = -leftDistance; x <= rightDistance; ++x) {
			if (x == 0 || y == 0) {
				FLocation targetLocation = pieceLocation.add(FLocation(x, y));
				missionBoard->setBoardSquareReachable(targetLocation);
			}
		}
	}

}

void UAbilityMarch::updateCurrentSpeed(FLocation pieceLocation, FLocation targetLocation) {
	setAbilityDirection(pieceLocation, targetLocation);

	// check what current direction is
	checkIfTargetOnHorizontal(pieceLocation, targetLocation);
	checkIfTargetOnVertical(pieceLocation, targetLocation);

	switch (lastMarchDirection) {
		case EAbilityDirection::ENone: {
			// first time
			upDistance = abilityDistance;
			downDistance = abilityDistance;
			leftDistance = abilityDistance;
			rightDistance = abilityDistance;
			break;
		}
		case EAbilityDirection::EUp: {
			if (targetInUp) {
				upDistance = upDistance * 2;
			}
			else {
				upDistance = abilityDistance;
			}
			break;
		}
		case EAbilityDirection::EDown: {
			if (targetInDown) {
				downDistance = downDistance * 2;
			}
			else {
				downDistance = abilityDistance;
			}
			break;
		}
		case EAbilityDirection::ELeft: {
			if (targetInLeft) {
				leftDistance = leftDistance * 2;
			}
			else {
				leftDistance = abilityDistance;
			}
			break;
		}
		case EAbilityDirection::ERight: {
			if (targetInRight) {
				rightDistance = rightDistance * 2;
			}
			else {
				rightDistance = abilityDistance;
			}
			break;
		}
	}

	if (targetInUp) {
		lastMarchDirection = EAbilityDirection::EUp;
	}
	if (targetInDown) {
		lastMarchDirection = EAbilityDirection::EDown;
	}
	if (targetInLeft) {
		lastMarchDirection = EAbilityDirection::ELeft;
	}
	if (targetInRight) {
		lastMarchDirection = EAbilityDirection::ERight;
	}
}

void UAbilityMarch::missionResetAbility() {
	lastMarchDirection = EAbilityDirection::ENone;
}