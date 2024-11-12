// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityMovingShot.generated.h"

UCLASS()
class UAbilityMovingShot : public UPieceAbilityMove
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool moveSection = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool shootSection = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool killedPeople = false;

public:
	UAbilityMovingShot();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, 
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
		UBoard*& missionBoard, UBoard*& revealedBoard) override;

	virtual bool isAbilityAvailable(APiece*& owner);

	// if kill someone, cost the point, but still enable ability
	virtual void abilityFinishedEffect(APiece*& owner) override;

};