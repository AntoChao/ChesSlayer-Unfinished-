// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilitySlashAndShoot.generated.h"

UCLASS()
class UAbilitySlashAndShoot : public UPieceAbilityMove
{
	GENERATED_BODY()

public:
	UAbilitySlashAndShoot();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};