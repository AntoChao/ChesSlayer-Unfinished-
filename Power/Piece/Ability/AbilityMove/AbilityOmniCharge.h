// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityOmniCharge.generated.h"

UCLASS()
class UAbilityOmniCharge : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityOmniCharge();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};