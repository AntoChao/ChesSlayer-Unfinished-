// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilitySilentStrike.generated.h"

UCLASS()
class UAbilitySilentStrike : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilitySilentStrike();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};