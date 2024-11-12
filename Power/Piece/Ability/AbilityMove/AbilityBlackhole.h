// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityBlackhole.generated.h"

UCLASS()
class UAbilityBlackhole : public UPieceAbilityMove
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Objective")
		TSubclassOf<class APiece> blackholePieceClass;

public:
	UAbilityBlackhole();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, 
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation,
		UBoard*& missionBoard, UBoard*& revealedBoard) override;
};