// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityHelpingHand.generated.h"

UCLASS()
class UAbilityHelpingHand : public UPieceAbilityMove
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int helpingHandDetectDistance = 5;

public:
	UAbilityHelpingHand();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, 
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
};