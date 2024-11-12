// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityDarkRitual.h"

UAbilityDarkRitual::UAbilityDarkRitual() {

}

void UAbilityDarkRitual::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);
}

void UAbilityDarkRitual::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isTargetCheckedEffect(owner, targetLocation, missionBoard, revealedBoard);
}