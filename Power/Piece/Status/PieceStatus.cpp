// Copyright Epic Games, Inc. All Rights Reserved.

#include "PieceStatus.h"

UPieceStatus::UPieceStatus() {

}

void UPieceStatus::setIfIsPersistent(bool state) {
	isPersistent = state;
}

bool UPieceStatus::getIfIsPersistent() {
	return isPersistent;
}

void UPieceStatus::applyStatus(APiece* aPiece) {
	return;
}