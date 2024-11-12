// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MissionObjective.h"
#include "MissionObjectiveDefense.generated.h"

UCLASS()
class UMissionObjectiveDefense : public UMissionObjective
{
	GENERATED_BODY()

public:
	UMissionObjectiveDefense();

public:
	virtual TArray<UPower*> selectParticipantPowers(TArray<UPower*> allPowers) override;

	virtual void selectTargetPieces(TArray<UPower*> allPowers) override;
	
	virtual void generateParticipantInitLocation(TArray<UPower*>& participantPowers,
		UBoard* missionBoard) override;

	virtual void generateTargetLocations(TArray<UPower*> participantPowers,
		UBoard* missionBoard) override;

	// in game objective check
	virtual bool isObjectiveCompleted(UCSMission* aMission) override;
};
