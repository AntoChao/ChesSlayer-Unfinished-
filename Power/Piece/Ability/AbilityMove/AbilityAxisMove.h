// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityAxisMove.generated.h"

UCLASS(Blueprintable)
class UAbilityAxisMove : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityAxisMove();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
};