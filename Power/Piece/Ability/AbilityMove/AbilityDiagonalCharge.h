// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityDiagonalCharge.generated.h"

UCLASS()
class UAbilityDiagonalCharge : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityDiagonalCharge();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};