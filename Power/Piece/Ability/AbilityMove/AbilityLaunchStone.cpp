// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityLaunchStone.h"

UAbilityLaunchStone::UAbilityLaunchStone() {

}

void UAbilityLaunchStone::isSelectedEffect(APiece*& owner, FLocation targetLocation,
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

void UAbilityLaunchStone::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	isTargetChecked = true;

	// delegate the logic to stone class
	// APiece* stone = Cast<APiece>GetWorld()->SpawnActor<ABlackholePiece>(blackholePieceClass, 
	// FVector::ZeroVector, FRotator::ZeroRotator);

	ABoardSquare* squareToThrowStone = missionBoard->getBoardSquareAtLocation(targetLocation);
	if (squareToThrowStone) {
		// squareToThrowStone->setIsOccupied(stone);
		missionBoard->resetBoardSquareReachability();
	}
}
