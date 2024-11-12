// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityLongShot.generated.h"

UCLASS()
class UAbilityLongShot : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityLongShot();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};