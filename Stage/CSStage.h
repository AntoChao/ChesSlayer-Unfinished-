// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// power to recognize

// board
#include "Board/Board.h"
#include "Board/BoardGenerator.h"

// objective
#include "Objective/MissionObjective.h"
#include "Objective/MissionObjectiveGenerator.h"

#include "CSStage.generated.h"

// forward declaration
class APower;

UCLASS(Blueprintable)
class UCSStage: public UObject
{
	GENERATED_BODY()

public:
	UCSStage();

	// current missions
	UPROPERTY(BlueprintReadWrite)
		TArray<UCSMission*> map;

	UPROPERTY(BlueprintReadWrite)
		TArray<FPath> paths;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		UCSMission* currentMission;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		int TotalLevelsBase = 21;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		int TotalLevels = 21;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		int MinMissionsPerLevel = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		int MaxMissionsPerLevel = 3;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		TSubclassOf<UCSMission> missionClass;

	UFUNCTION(BlueprintCallable)
		void loadMapGenerationParameters(int difficulty, int stageNum);

	UFUNCTION(BlueprintCallable)
		void generateMap();

	// if a mission got selected, should initialize it
	UFUNCTION(BlueprintCallable)
		void selectMission();
};