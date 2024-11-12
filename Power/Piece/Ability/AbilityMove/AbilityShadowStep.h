// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityShadowStep.generated.h"

UCLASS()
class UAbilityShadowStep : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityShadowStep();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};