// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MissionObjective.h"
#include "MissionObjectiveSurvival.generated.h"

UCLASS()
class UMissionObjectiveSurvival : public UMissionObjective
{
	GENERATED_BODY()

public:
	UMissionObjectiveSurvival();

public:
	// in game objective check
	virtual bool isObjectiveCompleted(UCSMission* aMission) override;

	virtual TArray<UPower*> selectParticipantPowers(TArray<UPower*> allPowers) override;

	virtual void selectTargetPieces(TArray<UPower*> allPowers) override;
	
	virtual void generateParticipantInitLocation(TArray<UPower*>& participantPowers,
		UBoard* missionBoard) override;

	virtual void generateTargetLocations(TArray<UPower*> participantPowers,
		UBoard* missionBoard) override;
};
