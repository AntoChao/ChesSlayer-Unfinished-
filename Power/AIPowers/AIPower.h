// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "../Power.h"
#include "Kismet/GameplayStatics.h"
#include "AIPower.generated.h"


UCLASS(Blueprintable)
class UAIPower : public UPower
{
	GENERATED_BODY()

public:
	UAIPower();

protected:
	/**
	* AI power should consider the type of mission
	* the grid value calculation depends on type of mission
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		bool isAITurn;

	virtual void InitPower(int aDifficulty, int currentStage, TArray<APiece*> selectedPieces) override;

	virtual void setMaxArmyEnergy(int difficulty, int currentStage) override;
};
