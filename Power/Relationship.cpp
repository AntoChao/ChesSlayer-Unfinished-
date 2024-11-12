// Copyright Epic Games, Inc. All Rights Reserved.

#include "Relationship.h"

URelationship::URelationship() {

}

// relationship methods
ERelationship URelationship::getRelationship(EPowerName thePowerName) {
	switch (thePowerName) {
	case EPowerName::EPlayer:
		return getPlayerRelationship();
	case EPowerName::EEmpire:
		return getEmpireRelationship();
	case EPowerName::EBandit:
		return getBanditRelationship();
	case EPowerName::EForeiger:
		return getForeigerRelationship();
	default:
		return ERelationship::ENeutro;
	}
}

ERelationship URelationship::getPlayerRelationship() {
	if (relationWithPlayer > NeutroMax) {
		return ERelationship::EAlly;
	}
	else if (relationWithPlayer < NeutroMin) {
		return ERelationship::EEnemy;
	}
	else {
		return ERelationship::ENeutro;
	}
}

ERelationship URelationship::getEmpireRelationship() {
	if (relationWithEmpire > NeutroMax) {
		return ERelationship::EAlly;
	}
	else if (relationWithPlayer < NeutroMin) {
		return ERelationship::EEnemy;
	}
	else {
		return ERelationship::ENeutro;
	}
}

ERelationship URelationship::getBanditRelationship() {
	if (relationWithBandit > NeutroMax) {
		return ERelationship::EAlly;
	}
	else if (relationWithPlayer < NeutroMin) {
		return ERelationship::EEnemy;
	}
	else {
		return ERelationship::ENeutro;
	}
}

ERelationship URelationship::getForeigerRelationship() {
	if (relationWithForeiger > NeutroMax) {
		return ERelationship::EAlly;
	}
	else if (relationWithPlayer < NeutroMin) {
		return ERelationship::EEnemy;
	}
	else {
		return ERelationship::ENeutro;
	}
}

// Update values
void URelationship::updateRelationWithPlayer(int value) {
	relationWithPlayer += value;
}

void URelationship::updateRelationWithEmpire(int value) {
	relationWithEmpire += value;
}

void URelationship::updateRelationWithBandit(int value) {
	relationWithBandit += value;
}

void URelationship::updateRelationWithForeiger(int value) {
	relationWithForeiger += value;
}

// Setter & Getter
void URelationship::setRelationWithPlayer(int value) {
	relationWithPlayer = value;
}

int URelationship::getRelationWithPlayer() {
	return relationWithPlayer;
}


void URelationship::setRelationWithEmpire(int value) {
	relationWithEmpire = value;
}

int URelationship::getRelationWithEmpire() {
	return relationWithEmpire;
}


void URelationship::setRelationWithBandit(int value) {
	relationWithBandit = value;
}

int URelationship::getRelationWithBandit() {
	return relationWithBandit;
}


void URelationship::setRelationWithForeiger(int value) {
	relationWithForeiger = value;
}

int URelationship::getRelationWithForeiger() {
	return relationWithForeiger;
}