// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityAxisCharge.generated.h"

UCLASS(Blueprintable)
class UAbilityAxisCharge : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityAxisCharge();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};