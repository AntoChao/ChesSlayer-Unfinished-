// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CSGameMode.h"

#include "PostgameGameMode.generated.h"

UCLASS()
class APostgameGameMode : public ACSGameMode
{
	GENERATED_BODY()

public:
	APostgameGameMode();

	virtual void BeginPlay() override;

protected:
	virtual void loadInstanceAttributes() override;
	virtual void updateInstance() override;

	// game values to initialize
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		int currentDifficulty = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<APiece*> unlockedPieces;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		bool isGameWon = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		int totalStageNum = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		int currentStage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<UCSStage*> allStages;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<UPower*> currentAllPowers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		int currentEnemiesKilledCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<APiece*> newUnlockedPieces;


};



