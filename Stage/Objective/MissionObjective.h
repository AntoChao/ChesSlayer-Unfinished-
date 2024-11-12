// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "../../CSCommonType.h"
#include "MissionObjective.generated.h"

// forward declaration
class UCSMission;
class APower;

UCLASS(Blueprintable)
class UMissionObjective : public UObject
{
	GENERATED_BODY()

public:
	UMissionObjective();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		EObjective missionObjective;

	/*all locations: lt, l, ld, d, rd, r, rt, t, c*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		TArray<FLocation> allLocations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		TArray<APiece*> targetPieces;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		TArray<FLocation> targetLocations;

	/*to store the accepted init location, avoid chosing the same*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		TArray<FLocation> currentLocations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		int initLocationNoise = 2;

	/*turn to survive*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		int targetTurnNum;

public:
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void setObjective(EObjective aObjective);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		EObjective getObjective();

	// initialize objective
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void initializeObjective(UCSMission*& aMission);

	// support power functions
		// give the power name and select them
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void selectPowerByName(TArray<UPower*>& allPowers,
			TArray<EPowerName> powerNames);

		// given the max number, return back at least 2, at max maxNum
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		int selectRandomNumber(int maxNum);

		// select player + (maxNum - 1) other powers
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		TArray<UPower*> selectRandomPowerByNum(TArray<UPower*>& allPowers, int maxNum);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		EPowerName getRandomPowerName();

		// participant powers
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		virtual TArray<UPower*> selectParticipantPowers(TArray<UPower*> allPowers);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		virtual void generateParticipantInitLocation(TArray<UPower*>& participantPowers,
			UBoard* missionBoard);

	// support location functions
		/*this function set the spawn distance base on the stage*/
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void initializeAllLocation(UBoard* missionBoard);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void initializeLocationNoise(int aCurrentStage);


		/*get a random l, ld, d, rd, r, ru, u, lu, c location*/
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		FLocation getARandomLocation();

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		FLocation getARandomSideLocation();

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		FLocation getCenterLocation();

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void applyNoiseToAllLocation(TArray<FLocation>& allLocationToApply);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void applyNoiseToLocation(FLocation& aLocationsToApply);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		int calculateDistance(FLocation aLocation, FLocation anotherLocation);

		/*default location*/
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void setTwoPowerLocation(TArray<UPower*> participantPowers);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void setThreePowerLocationSides(TArray<UPower*> participantPowers);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		void setThreePowerLocationCenter(TArray<UPower*> participantPowers);

	// in game objective check
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		virtual bool isObjectiveCompleted(UCSMission* aMission);

		// target pieces
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		virtual void selectTargetPieces(TArray<UPower*> allPowers);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		TArray<APiece*> selectAllAILeaderPieces(TArray<UPower*> allPowers);

		/* select ally if player has ally, else select player piece*/
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		UPower* selectPlayerPower(TArray<UPower*> allPowers);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		UPower* selectRandomAllyPower(TArray<UPower*> allPowers);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		UPower* selectRandomNeutroPower(TArray<UPower*> allPowers);

		/* player must have enemy power, else game ended already*/
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		UPower* selectRandomEnemyPower(TArray<UPower*> allPowers);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		APiece* selectRandomArmyPiece(UPower* aPower);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		APiece* selectRandomPiece(TArray<APiece*> allPieces);

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		bool isAllTargetPiecesDied();

	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		bool isAnyTargetPiecesDied();

		// target location
	UFUNCTION(BlueprintCallable, Category = "Objective Method")
		virtual void generateTargetLocations(TArray<UPower*> participantPowers,
			UBoard* missionBoard);

	
};
