// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityLJump.generated.h"

UCLASS()
class UAbilityLJump : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityLJump();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};