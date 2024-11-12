// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MissionObjective.h"
#include "MissionObjectiveDefeat.generated.h"

UCLASS()
class UMissionObjectiveDefeat : public UMissionObjective
{
	GENERATED_BODY()

public:
	UMissionObjectiveDefeat();

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
