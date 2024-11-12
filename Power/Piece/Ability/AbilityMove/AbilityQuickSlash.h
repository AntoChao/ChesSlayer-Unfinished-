// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityQuickSlash.generated.h"

UCLASS()
class UAbilityQuickSlash : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilityQuickSlash();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};