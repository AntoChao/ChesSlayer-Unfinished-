// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilitySwiftStep.generated.h"

UCLASS()
class UAbilitySwiftStep : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilitySwiftStep();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};