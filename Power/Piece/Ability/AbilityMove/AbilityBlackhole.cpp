// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityBlackhole.h"

UAbilityBlackhole::UAbilityBlackhole() {

}

void UAbilityBlackhole::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);
	
	FLocation pieceLocation = owner->getPieceSquare()->getInBoardLocation();

	for (int y = -abilityDistance; y <= abilityDistance; ++y) {
		for (int x = -abilityDistance; x <= abilityDistance; ++x) {
			if (FMath::Abs(x) + FMath::Abs(y) == abilityDistance) {
				FLocation targetLocation = pieceLocation.add(FLocation(x, y));
				missionBoard->setBoardSquareReachable(targetLocation);
			}
		}
	}
}

void UAbilityBlackhole::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	isTargetChecked = true;

	// delegate the logic of pull for black hole class
	// APiece* blackhole = Cast<APiece>GetWorld()->SpawnActor<ABlackholePiece>(blackholePieceClass, 
	// FVector::ZeroVector, FRotator::ZeroRotator);
	
	ABoardSquare* squareToInvokeBlackhole = missionBoard->getBoardSquareAtLocation(targetLocation);
	if (squareToInvokeBlackhole) {
		// squareToInvokeBlackhole->setIsOccupied(blackhole);
		missionBoard->resetBoardSquareReachability();
	}
}