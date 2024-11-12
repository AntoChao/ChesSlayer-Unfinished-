// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityQuickDraw.generated.h"

UCLASS()
class UAbilityQuickDraw : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityQuickDraw();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, 
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
};