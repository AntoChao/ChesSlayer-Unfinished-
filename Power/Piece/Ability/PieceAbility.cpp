// Copyright Epic Games, Inc. All Rights Reserved.

#include "PieceAbility.h"

UPieceAbility::UPieceAbility() {

}


void UPieceAbility::setAbilityName(FName anAbilityName) {
	abilityName = anAbilityName;
}

FName UPieceAbility::getAbilityName() {
	return abilityName;
}


void UPieceAbility::setAbilityType(EAbilityType aAbilityType) {
	abilityType = aAbilityType;
}

EAbilityType UPieceAbility::getAbilityType() {
	return abilityType;
}


void UPieceAbility::setIsUnique(bool uniqueness) {
	isUnique = uniqueness;
}

bool UPieceAbility::getIfIsUnique() {
	return isUnique;
}


void UPieceAbility::setAbilityDirection(FLocation pieceLocation, FLocation targetLocation) {
	FLocation shiftLocation = targetLocation.subtract(pieceLocation);

	if (shiftLocation.x < 0) {
		abilityXDirection = EAbilityDirection::ELeft;
	}
	else {
		if (shiftLocation.x > 0) {
			abilityXDirection = EAbilityDirection::ERight;
		}
		else {
			abilityXDirection = EAbilityDirection::ENone;
		}
	}

	if (shiftLocation.y < 0) {
		abilityYDirection = EAbilityDirection::EUp;
	}
	else {
		if (shiftLocation.y > 0) {
			abilityYDirection = EAbilityDirection::EDown;
		}
		else {
			abilityXDirection = EAbilityDirection::ENone;
		}
	}
}

FLocation UPieceAbility::getNewLocationByDirection(FLocation pieceLocation, int moveDistance) {
	int newX = 0;
	int newY = 0;

	switch (abilityXDirection) {
		case EAbilityDirection::ELeft: {
			newX = -1 * moveDistance;
		}
		case EAbilityDirection::ERight: {
			newX = moveDistance;
		}
	}

	switch (abilityYDirection) {
		case EAbilityDirection::EUp: {
			newY = -1 * moveDistance;
		}
		case EAbilityDirection::EDown: {
			newY = moveDistance;
		}
	}
	return FLocation(newX, newY);
}

EAbilityDirection UPieceAbility::getReverseDirection(EAbilityDirection aDirection) {
	switch (aDirection) {
	case EAbilityDirection::EUp: {
		return EAbilityDirection::EDown;
	}
	case EAbilityDirection::EDown: {
		return EAbilityDirection::EUp;
	}
	case EAbilityDirection::ELeft: {
		return EAbilityDirection::ERight;
	}
	case EAbilityDirection::ERight: {
		return EAbilityDirection::ELeft;
	}
	default:
		return EAbilityDirection::ENone;
	}
}

EAbilityDirection UPieceAbility::getOmniDirection() {
	if (abilityXDirection == EAbilityDirection::ELeft && abilityYDirection == EAbilityDirection::EUp) {
		return EAbilityDirection::EUpLeft;
	}
	if (abilityXDirection == EAbilityDirection::ENone && abilityYDirection == EAbilityDirection::EUp) {
		return EAbilityDirection::EUp;
	}
	if (abilityXDirection == EAbilityDirection::ERight && abilityYDirection == EAbilityDirection::EUp) {
		return EAbilityDirection::EUpRight;
	}
	if (abilityXDirection == EAbilityDirection::ERight && abilityYDirection == EAbilityDirection::ENone) {
		return EAbilityDirection::ERight;
	}
	if (abilityXDirection == EAbilityDirection::ERight && abilityYDirection == EAbilityDirection::EDown) {
		return EAbilityDirection::EDownRight;
	}
	if (abilityXDirection == EAbilityDirection::ENone && abilityYDirection == EAbilityDirection::EDown) {
		return EAbilityDirection::EDown;
	}
	if (abilityXDirection == EAbilityDirection::ELeft && abilityYDirection == EAbilityDirection::EDown) {
		return EAbilityDirection::EDownLeft;
	}
	if (abilityXDirection == EAbilityDirection::ELeft && abilityYDirection == EAbilityDirection::ENone) {
		return EAbilityDirection::ELeft;
	}
	return EAbilityDirection::ENone;
}


// for passive ability
void UPieceAbility::equipAbilityEffect(APiece*& owner) {
	return;
}

void UPieceAbility::unequipAbilityEffect(APiece*& owner) {
	return;
}


// for active ability
void UPieceAbility::activate(APiece*& owner, FLocation targetLocation, 
	UBoard*& missionBoard, UBoard*& revealedBoard) {
		/*check energy point and move point*/
	if (isAbilityAvailable(owner)) {
		owner->setIsAbilityCanBeSelected(true);
		switch (abilityType) {
			case EAbilityType::EPassive: {
				break;
			}
			case EAbilityType::EMove:
			case EAbilityType::EBuff: {
				if (isSelected) {
					if (isTargetChecked) {
						isTargetCheckedEffect(owner, targetLocation, missionBoard, revealedBoard);
						abilityFinishedEffect(owner);
					}
				}
				else {
					isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);
				}
				break;
			}
			case EAbilityType::EControl: {
				if (isSelected) {
					if (isTargetChecked) {
						if (!isControledTargetChecked) {
							isControledTargetCheckedEffect(owner, targetLocation, missionBoard, revealedBoard);
							abilityFinishedEffect(owner);
						}
					}
					else {
						isTargetCheckedEffect(owner, targetLocation, missionBoard, revealedBoard);
					}
				}
				else {
					isSelectedEffect(owner, targetLocation, missionBoard, revealedBoard);
				}
				break;
			}
		}
	}
	else {
		owner->setIsAbilityCanBeSelected(false);
	}
}

void UPieceAbility::isSelectedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	isSelected = true;
}

void UPieceAbility::isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	isTargetChecked = true;
}

void UPieceAbility::isControledTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
	UBoard*& missionBoard, UBoard*& revealedBoard) {
	isControledTargetChecked = true;
}

	/*ability should check the if it is possible to use in the first place*/
void UPieceAbility::abilityFinishedEffect(APiece*& owner) {
	turnResetAbility();
	owner->updateCurrentEnergyPoint(-energyCost);
	owner->updateCurrentMovePoint(-movePointCost);
}

bool UPieceAbility::isAbilityAvailable(APiece*& owner) {
	return owner->getCurrentMovePoint() >= movePointCost &&
		owner->getCurrentEnergyPoint() >= energyCost;
}

void UPieceAbility::turnResetAbility() {
	isSelected = false; 
	isTargetChecked = false; 	
	isControledTargetChecked = false;
}

void UPieceAbility::missionResetAbility() {
	return;
}