// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "../../../CSCommonType.h"

// all abilities
	// move abiltiies
#include "AbilityMove/AbilityAxisCharge.h"
#include "AbilityMove/AbilityAxisMove.h"
#include "AbilityMove/AbilityBackstab.h"
#include "AbilityMove/AbilityBlackhole.h"
#include "AbilityMove/AbilityBroomFlight.h"
#include "AbilityMove/AbilityDarkRitual.h"
#include "AbilityMove/AbilityDiagonalCharge.h"
#include "AbilityMove/AbilityHelpingHand.h"
#include "AbilityMove/AbilityHunt.h"
#include "AbilityMove/AbilityLaunchStone.h"
#include "AbilityMove/AbilityLeapingHunt.h"
#include "AbilityMove/AbilityLJump.h"
#include "AbilityMove/AbilityLongShot.h"
#include "AbilityMove/AbilityMarch.h"
#include "AbilityMove/AbilityMovingShot.h"
#include "AbilityMove/AbilityOmniCharge.h"
#include "AbilityMove/AbilityOmniMove.h"
#include "AbilityMove/AbilityPetStep.h"
#include "AbilityMove/AbilityPortal.h"
#include "AbilityMove/AbilityQuickDraw.h"
#include "AbilityMove/AbilityQuickSlash.h"
#include "AbilityMove/AbilityRush.h"
#include "AbilityMove/AbilityShadowStep.h"
#include "AbilityMove/AbilitySheldPush.h"
#include "AbilityMove/AbilitySilentStrike.h"
#include "AbilityMove/AbilitySlashAndShoot.h"
#include "AbilityMove/AbilitySpearVault.h"
#include "AbilityMove/AbilitySwiftStep.h"


#include "PieceAbilityGenerator.generated.h"

UCLASS(Blueprintable)
class UPieceAbilityGenerator: public UObject
{
	GENERATED_BODY()

public:
	UPieceAbilityGenerator();

	static UPieceAbilityGenerator* GetPieceAbilityGeneratorInstance();

	static void SetPieceAbilityGeneratorClass(TSubclassOf<UPieceAbilityGenerator> NewClass);

protected:
	// Static instance of the singleton
	static UPieceAbilityGenerator* SingletonPieceAbilityAbilityGeneratorInstance;
	
	// Default class to spawn, can be set via Blueprint
	static TSubclassOf<UPieceAbilityGenerator> PieceAbilityGeneratorClass;


	FActorSpawnParameters SpawnParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		int totalAbilityNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> axisChargeClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName axisChargeName = FName("Axis Charge");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> axisMoveClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName axisMoveName = FName("Axis Move");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> backstabClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName backstabName = FName("Backstab");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> blackholeClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName blackholeName = FName("Blackhole");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> broomFlightClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName broomFlightName = FName("Broom Flight");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> diagonalChargeClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName diagonalChargeName = FName("Diagonal Charge");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> helpingHandClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName helpingHandName = FName("Helping Hand");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> huntClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName huntName = FName("Hunt");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> launchStoneClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName launchStoneName = FName("Launch Stone");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> leapingHuntClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName leapingHuntName = FName("Leaping Hunt");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> lJumpClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName lJumpName = FName("L Jump");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> longShotClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName longShotName = FName("Long Shot");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> marchClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName marchName = FName("March");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> movingShotClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName movingShotName = FName("Moving Shot");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> omniChargeClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName omniChargeName = FName("Omni Charge");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> omniMoveClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName omniMoveName = FName("Omni Move");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> petStepClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName petStepName = FName("Pet Step");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> portalClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName portalName = FName("Portal");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> quickDrawClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName quickDrawName = FName("Quick Draw");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> quickSlashClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName quickSlashName = FName("Quick Slash");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> rushClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName rushName = FName("Rush");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> shadowStepClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName shadowStepName = FName("Shadow Step");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> sheldPushClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName sheldPushName = FName("Sheld Push");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> slashAndShootClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName slashAndShootName = FName("Slash & Shoot");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> spearVaultClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName spearVaultName = FName("Spear Vault");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		TSubclassOf<class UAbilityAxisCharge> swiftStepClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "All Ability")
		FName swiftStepName = FName("Swift Step");

public:
	UFUNCTION(BlueprintCallable, Category = "All Ability")
		UPieceAbility* generateARandomAbility(APiece*& owner);

	UFUNCTION(BlueprintCallable, Category = "Mission Objective")
		UPieceAbility* generateASpecificAbility(APiece*& owner, EAbilityName aAbilityEnum);

	UFUNCTION(BlueprintCallable, Category = "Mission Objective")
		FName getAbilityName(EAbilityName aAbilityEnum);
};

	
