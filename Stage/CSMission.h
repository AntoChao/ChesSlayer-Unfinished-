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

#include "CSMission.generated.h"

// forward declaration
class APower;
class ABoard;

UCLASS(Blueprintable)
class UCSMission : public UObject
{
	GENERATED_BODY()

public:
	UCSMission();

protected:
	// mission info
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Attribute")
		class UTexture2D* pieceImage;

	// mission stats
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		int currentStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Attribute")
		int missionLevel;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		bool isBossMission; /*last mission of a stage*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		TSubclassOf<UMissionObjectiveGenerator> objectiveGeneratorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		UMissionObjectiveGenerator* objectiveGenerator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		UMissionObjective* objective;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		bool isMissionCompleted = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		bool isMissionWon = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		bool isDay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		TArray<UPower*> participantsPowers;
	
		// board
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		TSubclassOf<UBoardGenerator> boardGeneratorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Mission Info")
		UBoardGenerator* boardGenerator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		UBoard* missionBoard;

	// mission proceding
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		int turnCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mission Attribute")
		int currentParticipantIndex = 0;

public:
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void initializeMission(int aStage);

	// mission stats methods
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setCurrentStage(int aStage);
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		int getCurrentStage();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setMissionLevel(int aLevel);
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		int getMissionLevel();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsBossMission(bool aState);
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool getIsBossMission();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setObjective(UMissionObjective*& aObjective);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		UMissionObjective* getObjective();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void generateRandomObjective();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void generateSpecificObjective(EObjective aObjective);


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsMissionCompleted(bool missionState);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool getIsMissionCompleted();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void checkMissionCompleteness();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsMissionWon(bool missionState);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool getIsMissionWon();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsDay(bool dayState);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool getIsDay();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setParticipantPowers(TArray<UPower*>& powers);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		TArray<UPower*>& getParticipantPowers();

	/* Board*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setMissionBoard(UBoard* aBoard);
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		UBoard*& getMissionBoard();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		virtual void generateBoard();

	// mission proceding methods
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void orderParticipantPowers(); /*define the turn order*/

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void startPowerTurn();
	
		/*it is called after each action*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void powerActionFinished(EPowerName powerName); /*called by power*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void powerTurnFinished(EPowerName powerName); /*called by power*/

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void missionCompletedEffect();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setTurnCount(int turnAmount);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		int getTurnCount();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void updateTurnCount(int modifier);
};