// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlayerPower.h"

#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"

UPlayerPower::UPlayerPower()
{
}

void UPlayerPower::InitPower(int aDifficulty, int currentStage, TArray<APiece*> selectedPieces) {
	army = selectedPieces;
}

void UPlayerPower::setMaxArmyEnergy(int difficulty, int currentStage) {
	int aNumber = 5;
	armyMaxEnergy = getNoisedValue(aNumber, armyDefaultNoise);
}