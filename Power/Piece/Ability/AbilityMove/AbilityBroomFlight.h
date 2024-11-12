// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityBroomFlight.generated.h"

UCLASS()
class UAbilityBroomFlight : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityBroomFlight();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};