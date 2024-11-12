// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilitySpearVault.h"

UAbilitySpearVault::UAbilitySpearVault() {

}

void UAbilitySpearVault::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);
}

void UAbilitySpearVault::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	UPieceAbilityMove::isTargetCheckedEffect(owner, targetLocation, missionBoard, revealedBoard);
}