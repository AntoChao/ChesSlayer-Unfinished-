// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityOmniMove.generated.h"

UCLASS()
class UAbilityOmniMove : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityOmniMove();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};