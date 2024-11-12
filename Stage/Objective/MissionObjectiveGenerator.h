// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "MissionObjectiveAssassin.h"
#include "MissionObjectiveCapture.h"
#include "MissionObjectiveDefeat.h"
#include "MissionObjectiveDefense.h"
#include "MissionObjectiveEscort.h"
#include "MissionObjectiveRescue.h"
#include "MissionObjectiveSurvival.h"

#include "../../CSCommonType.h"
#include "MissionObjectiveGenerator.generated.h"

UCLASS()
class UMissionObjectiveGenerator : public UObject
{
	GENERATED_BODY()

public:
	UMissionObjectiveGenerator();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Objective")
		TSubclassOf<class UMissionObjectiveAssassin> objectiveAssassin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Objective")
		TSubclassOf<class UMissionObjectiveCapture> objectiveCapture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Objective")
		TSubclassOf<class UMissionObjectiveDefeat> objectiveDefeat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Objective")
		TSubclassOf<class UMissionObjectiveDefense> objectiveDefense;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Objective")
		TSubclassOf<class UMissionObjectiveEscort> objectiveEscort;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Objective")
		TSubclassOf<class UMissionObjectiveRescue> objectiveRescue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Objective")
		TSubclassOf<class UMissionObjectiveSurvival> objectiveSurvival;

public:
	UFUNCTION(BlueprintCallable, Category = "Mission Objective")
		UMissionObjective* generateARandomMission(UCSMission* owner);

	UFUNCTION(BlueprintCallable, Category = "Mission Objective")
		UMissionObjective* generateASpecificMission(UCSMission* owner, EObjective aObjective);
};

	
