// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilitySpearVault.generated.h"

UCLASS()
class UAbilitySpearVault : public UPieceAbilityMove
{
	GENERATED_BODY()

public:

	// test moving shot before implementation

	UAbilitySpearVault();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, 
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
};