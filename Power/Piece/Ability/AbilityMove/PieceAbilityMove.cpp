// Copyright Epic Games, Inc. All Rights Reserved.

#include "PieceAbilityMove.h"

UPieceAbilityMove::UPieceAbilityMove() {
	abilityType = EAbilityType::EMove;
}

void UPieceAbilityMove::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) {
	// UPieceAbility::isTargetCheckedEffect(owner, targetLocation, missionBoard, revealedBoard);

	ABoardSquare* squareToMove = missionBoard->getBoardSquareAtLocation(targetLocation);
	if (squareToMove) {
		squareToMove->setIsOccupied(missionBoard, owner);
		owner->updateFogOfWar(revealedBoard);
		missionBoard->resetBoardSquareReachability();
	}
}

void UPieceAbilityMove::checkIfTargetOnHorizontal(FLocation pieceLocation, FLocation targetLocation) {
	FLocation difDistance = targetLocation.subtract(pieceLocation);
	if (difDistance.x < 0) {
		targetInLeft = true;
	}
	else {
		if (difDistance.x > 0) {
			targetInRight = true;
		}
	}
}

void UPieceAbilityMove::checkIfTargetOnVertical(FLocation pieceLocation, FLocation targetLocation) {
	FLocation difDistance = targetLocation.subtract(pieceLocation);
	if (difDistance.y < 0) {
		targetInUp = true;
	}
	else {
		if (difDistance.x > 0) {
			targetInDown = true;
		}
	}
}

void UPieceAbilityMove::resetAllDirectionVariables() {
	upDistance = abilityDistance;
	downDistance = abilityDistance;
	leftDistance = abilityDistance;
	rightDistance = abilityDistance;
	targetInUp = false;
	targetInDown = false;
	targetInLeft = false;
	targetInRight = false;
}

void UPieceAbilityMove::setAllDirectionDistance() {
	if (targetInUp) {
		upDistance = specificAbilityDistance;
	}
	if (targetInDown) {
		downDistance = specificAbilityDistance;
	}
	if (targetInLeft) {
		leftDistance = specificAbilityDistance;
	}
	if (targetInRight) {
		rightDistance = specificAbilityDistance;
	}
}