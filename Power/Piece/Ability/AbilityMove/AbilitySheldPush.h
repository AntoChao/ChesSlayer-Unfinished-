// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilitySheldPush.generated.h"

UCLASS()
class UAbilitySheldPush : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilitySheldPush();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
		UBoard*& missionBoard, UBoard*& revealedBoard) override;

};