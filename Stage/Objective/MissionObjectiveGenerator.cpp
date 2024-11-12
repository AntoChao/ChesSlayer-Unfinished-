// Copyright Epic Games, Inc. All Rights Reserved.

#include "MissionObjectiveGenerator.h"

UMissionObjectiveGenerator::UMissionObjectiveGenerator() {
}

UMissionObjective* UMissionObjectiveGenerator::generateARandomMission(UCSMission* owner) {
	EObjective selectedObjected;
	int randNum = FMath::RandRange(0, 6);

	switch (randNum) {
	case 0: {
		selectedObjected = EObjective::EDefeat;
		break;
	}
	case 1: {
		selectedObjected = EObjective::EDefense;
		break;
	}
	case 2: {
		selectedObjected = EObjective::ESurvival;
		break;
	}
	case 3: {
		selectedObjected = EObjective::EAssassination;
		break;
	}
	case 4: {
		selectedObjected = EObjective::EEscort;
		break;
	}
	case 5: {
		selectedObjected = EObjective::ECapture;
		break;
	}
	case 6: {
		selectedObjected = EObjective::ERescue;
		break;
	}
	default:
		selectedObjected = EObjective::EDefeat;
		break;
	}

	return generateASpecificMission(owner, selectedObjected);
}

UMissionObjective* UMissionObjectiveGenerator::generateASpecificMission(UCSMission* owner, EObjective aObjective) {
	if (owner) {
		switch (aObjective) {
			case EObjective::EDefeat: {
				return NewObject<UMissionObjective>(owner, objectiveDefeat);
			}
			case EObjective::EDefense: {
				return NewObject<UMissionObjective>(owner, objectiveDefense);
			}
			case EObjective::ESurvival: {
				return NewObject<UMissionObjective>(owner, objectiveSurvival);
			}
			case EObjective::EAssassination: {
				return NewObject<UMissionObjective>(owner, objectiveAssassin);
			}
			case EObjective::EEscort: {
				return NewObject<UMissionObjective>(owner, objectiveEscort);
			}
			case EObjective::ECapture: {
				return NewObject<UMissionObjective>(owner, objectiveCapture);
			}
			case EObjective::ERescue: {
				return NewObject<UMissionObjective>(owner, objectiveRescue);
			}
			default:
				return NewObject<UMissionObjective>(owner, objectiveDefeat);
		}
	}
	else {
		return nullptr;
	}
}