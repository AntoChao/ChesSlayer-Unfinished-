// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityHunt.generated.h"

UCLASS()
class UAbilityHunt : public UPieceAbilityMove
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		APiece* targetPiece = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int huntDistance = 5;

public:
	UAbilityHunt();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
};