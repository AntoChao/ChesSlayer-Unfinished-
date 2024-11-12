// Copyright Epic Games, Inc. All Rights Reserved.

#include "PieceAbilityGenerator.h"

UPieceAbilityGenerator::UPieceAbilityGenerator() {
}

UPieceAbilityGenerator* UPieceAbilityGenerator::SingletonPieceAbilityAbilityGeneratorInstance = nullptr;
TSubclassOf<UPieceAbilityGenerator> UPieceAbilityGenerator::PieceAbilityGeneratorClass = UPieceAbilityGenerator::StaticClass();

void UPieceAbilityGenerator::SetPieceAbilityGeneratorClass(TSubclassOf<UPieceAbilityGenerator> NewClass) {
	PieceAbilityGeneratorClass = NewClass;
}

UPieceAbilityGenerator* UPieceAbilityGenerator::GetPieceAbilityGeneratorInstance() {
	if (SingletonPieceAbilityAbilityGeneratorInstance == nullptr) {
		// Create the singleton instance if it doesn't exist
		if (PieceAbilityGeneratorClass) {
			// SingletonInstance = NewObject<UMySingletonBase>(GetOuter(), SingletonClass);
			SingletonPieceAbilityAbilityGeneratorInstance = NewObject<UPieceAbilityGenerator>(GetTransientPackage(), PieceAbilityGeneratorClass);
			SingletonPieceAbilityAbilityGeneratorInstance->AddToRoot();
		}
	}
	return SingletonPieceAbilityAbilityGeneratorInstance;
}

UPieceAbility* UPieceAbilityGenerator::generateARandomAbility(APiece*& owner) {
	int randNum = FMath::RandRange(1, totalAbilityNum);
	EAbilityName randAbility = static_cast<EAbilityName>(randNum);
	
	return generateASpecificAbility(owner, randAbility);
}

UPieceAbility* UPieceAbilityGenerator::generateASpecificAbility(APiece*& owner, EAbilityName aAbilityEnum) {
	UPieceAbility* selectedAbility = nullptr;
	switch (aAbilityEnum) {
		case EAbilityName::ENone: {
			selectedAbility = nullptr;
			break;
		}
		case EAbilityName::EAxisCharge: {
			selectedAbility = NewObject<UPieceAbility>(owner, axisChargeClass);
			break;
		}
		case EAbilityName::EAxisMove: {
			selectedAbility = NewObject<UPieceAbility>(owner, axisMoveClass);
			break;
		}
		case EAbilityName::EBackstab: {
			selectedAbility = NewObject<UPieceAbility>(owner, backstabClass);
			break;
		}
		case EAbilityName::EBlackhole: {
			selectedAbility = NewObject<UPieceAbility>(owner, blackholeClass);
			break;
		}
		case EAbilityName::EBroomFlight: {
			selectedAbility = NewObject<UPieceAbility>(owner, broomFlightClass);
			break;
		}
		case EAbilityName::EDiagonalCharge: {
			selectedAbility = NewObject<UPieceAbility>(owner, diagonalChargeClass);
			break;
		}
		case EAbilityName::EHelpingHand: {
			selectedAbility = NewObject<UPieceAbility>(owner, helpingHandClass);
			break;
		}
		case EAbilityName::EHunt: {
			selectedAbility = NewObject<UPieceAbility>(owner, huntClass);
			break;
		}
		case EAbilityName::ELaunchStone: {
			selectedAbility = NewObject<UPieceAbility>(owner, launchStoneClass);
			break;
		}
		case EAbilityName::ELeapingHunt: {
			selectedAbility = NewObject<UPieceAbility>(owner, leapingHuntClass);
			break;
		}
		case EAbilityName::ELJump: {
			selectedAbility = NewObject<UPieceAbility>(owner, lJumpClass);
			break;
		}
		case EAbilityName::ELongShot: {
			selectedAbility = NewObject<UPieceAbility>(owner, longShotClass);
			break;
		}
		case EAbilityName::EMarch: {
			selectedAbility = NewObject<UPieceAbility>(owner, marchClass);
			break;
		}
		case EAbilityName::EMovingShot: {
			selectedAbility = NewObject<UPieceAbility>(owner, movingShotClass);
			break;
		}
		case EAbilityName::EOmniCharge: {
			selectedAbility = NewObject<UPieceAbility>(owner, omniChargeClass);
			break;
		}
		case EAbilityName::EOmniMove: {
			selectedAbility = NewObject<UPieceAbility>(owner, omniMoveClass);
			break;
		}
		case EAbilityName::EPetStep: {
			selectedAbility = NewObject<UPieceAbility>(owner, petStepClass);
			break;
		}
		case EAbilityName::EPortal: {
			selectedAbility = NewObject<UPieceAbility>(owner, portalClass);
			break;
		}
		case EAbilityName::EQuickDraw: {
			selectedAbility = NewObject<UPieceAbility>(owner, quickDrawClass);
			break;
		}
		case EAbilityName::EQuickSlash: {
			selectedAbility = NewObject<UPieceAbility>(owner, quickSlashClass);
			break;
		}
		case EAbilityName::ERush: {
			selectedAbility = NewObject<UPieceAbility>(owner, rushClass);
			break;
		}
		case EAbilityName::EShadowStep: {
			selectedAbility = NewObject<UPieceAbility>(owner, shadowStepClass);
			break;
		}
		case EAbilityName::ESheldPush: {
			selectedAbility = NewObject<UPieceAbility>(owner, sheldPushClass);
			break;
		}
		case EAbilityName::ESlashAndShoot: {
			selectedAbility = NewObject<UPieceAbility>(owner, slashAndShootClass);
			break;
		}
		case EAbilityName::ESpearVault: {
			selectedAbility = NewObject<UPieceAbility>(owner, spearVaultClass);
			break;
		}
		case EAbilityName::ESwiftStep: {
			selectedAbility = NewObject<UPieceAbility>(owner, swiftStepClass);
			break;
		}
	}

	if (selectedAbility) {
		FName selectedAbilityName = getAbilityName(aAbilityEnum);
		selectedAbility->setAbilityName(selectedAbilityName);
	}
	return selectedAbility;
}

// easier for multi language setting -> future implementation
FName UPieceAbilityGenerator::getAbilityName(EAbilityName aAbilityEnum) {
	switch (aAbilityEnum) {
		case EAbilityName::EAxisCharge: {
			return axisChargeName;
		}
		case EAbilityName::EAxisMove: {
			return axisMoveName;
		}
		case EAbilityName::EBackstab: {
			return backstabName;
		}
		case EAbilityName::EBlackhole: {
			return blackholeName;
		}
		case EAbilityName::EBroomFlight: {
			return broomFlightName;
		}
		case EAbilityName::EDiagonalCharge: {
			return diagonalChargeName;
		}
		case EAbilityName::EHelpingHand: {
			return helpingHandName;
		}
		case EAbilityName::EHunt: {
			return huntName;
		}
		case EAbilityName::ELaunchStone: {
			return launchStoneName;
		}
		case EAbilityName::ELeapingHunt: {
			return leapingHuntName;
		}
		case EAbilityName::ELJump: {
			return lJumpName;
		}
		case EAbilityName::ELongShot: {
			return longShotName;
		}
		case EAbilityName::EMarch: {
			return marchName;
		}
		case EAbilityName::EMovingShot: {
			return movingShotName;
		}
		case EAbilityName::EOmniCharge: {
			return omniChargeName;
		}
		case EAbilityName::EOmniMove: {
			return omniMoveName;
		}
		case EAbilityName::EPetStep: {
			return petStepName;
		}
		case EAbilityName::EPortal: {
			return portalName;
		}
		case EAbilityName::EQuickDraw: {
			return quickDrawName;
		}
		case EAbilityName::EQuickSlash: {
			return quickSlashName;
		}
		case EAbilityName::ERush: {
			return rushName;
		}
		case EAbilityName::EShadowStep: {
			return shadowStepName;
		}
		case EAbilityName::ESheldPush: {
			return sheldPushName;
		}
		case EAbilityName::ESlashAndShoot: {
			return slashAndShootName;
		}
		case EAbilityName::ESpearVault: {
			return spearVaultName;
		}
		case EAbilityName::ESwiftStep: {
			return swiftStepName;
		}
	}
	return FName("error");
}