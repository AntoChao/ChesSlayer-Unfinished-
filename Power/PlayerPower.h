// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Power.h"
#include "PlayerPower.generated.h"

UCLASS(Blueprintable)
class UPlayerPower : public UPower
{
	GENERATED_BODY()

public:
	UPlayerPower();

protected:
	virtual void InitPower(int aDifficulty, int currentStage, TArray<APiece*> selectedPieces) override;

	virtual void setMaxArmyEnergy(int difficulty, int currentStage) override;

};

