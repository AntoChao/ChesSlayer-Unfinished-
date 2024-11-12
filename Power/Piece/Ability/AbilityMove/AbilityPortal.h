// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityPortal.generated.h"

UCLASS()
class UAbilityPortal : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityPortal();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, 
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
};