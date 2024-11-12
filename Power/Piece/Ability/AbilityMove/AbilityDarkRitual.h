// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityDarkRitual.generated.h"

UCLASS()
class UAbilityDarkRitual : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityDarkRitual();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, 
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
};