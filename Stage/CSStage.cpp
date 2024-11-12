// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSStage.h"

// gamemode
#include "../Level/GameplayGameMode.h"

// power
#include "../Power/Power.h"

UCSStage::UCSStage() {
	
}

void UCSStage::loadMapGenerationParameters(int difficulty, int stageNum) {
    TotalLevels = TotalLevelsBase + difficulty * stageNum;
}

void UCSStage::generateMap() {
    // Clear any existing data
    map.Empty();
    paths.Empty();

    // Step 1: Generate the Missions for Each Level
    for (int Level = 0; Level < TotalLevels; Level++) {
        int NumMissions = FMath::RandRange(MinMissionsPerLevel, MaxMissionsPerLevel);

        for (int i = 0; i < NumMissions; i++) {
            // Create the mission and add it to the map
            UCSMission* NewMission = NewObject<UCSMission>(this, missionClass);
            NewMission->setMissionLevel(Level);  // Set the MissionLevel
            map.Add(NewMission);
        }
    }

    // Step 2: Create paths Between Missions on Adjacent Levels
    for (int Level = 0; Level < TotalLevels - 1; Level++) {
        // Find missions on the current and next levels
        TArray<UCSMission*> CurrentLevelMissions;
        TArray<UCSMission*> NextLevelMissions;

        for (UCSMission* Mission : map) {
            if (Mission->getMissionLevel() == Level) {
                CurrentLevelMissions.Add(Mission);
            }
            else if (Mission->getMissionLevel() == Level + 1) {
                NextLevelMissions.Add(Mission);
            }
        }

        // Create paths between missions on the current and next levels
        for (UCSMission* CurrentMission : CurrentLevelMissions) {
            int Numpaths = FMath::RandRange(1, NextLevelMissions.Num());

            for (int p = 0; p < Numpaths; p++) {
                int TargetIndex = FMath::RandRange(0, NextLevelMissions.Num() - 1);
                UCSMission* TargetMission = NextLevelMissions[TargetIndex];

                // Create a new path and add it to the paths array
                FPath NewPath(CurrentMission, TargetMission);
                paths.Add(NewPath);
            }
        }
    }

    // Log the result for debugging
    /*
    for (int Level = 0; Level < TotalLevels; Level++) {
        UE_LOG(LogTemp, Warning, TEXT("Level %d:"), Level);

        for (UCSMission* Mission : map) {
            if (Mission->missionLevel == Level) {
                UE_LOG(LogTemp, Warning, TEXT("Mission Type: %s"), *Mission->MissionType);
            }
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Paths:"));
    for (FPath& Path : paths) {
        UE_LOG(LogTemp, Warning, TEXT("From %s to %s"),
            *Path.FromMission->MissionType, *Path.ToMission->MissionType);
    }*/ 
}

void UCSStage::selectMission() {
    return;
}