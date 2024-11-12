// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"

#include "../Power/Power.h"
#include "../Power/Piece/Piece.h"

#include "../Stage/CSMission.h"
#include "../Stage/CSStage.h"

#include "../Power/Piece/PieceGenerator.h"
#include "../Power/Piece/Ability/PieceAbilityGenerator.h"

#include "CSInstance.generated.h"

UCLASS(Blueprintable)
class UCSInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UCSInstance();

protected:
	// Common values
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		bool isFirstTimeOpening;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		ELanguage gameLanguage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		bool isLastGameFinished;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		int currentDifficulty = 0;

	/* all already unlocked pieces avaliable to select in startgame */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TArray<FName> unlockedPieceNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TArray<APiece*> unlockedPieces;

	/* save pieces that are unlocked by achieve x condition
	   it merge to the unlockedPieces in postgame */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<FName> newUnlockedPieceNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TArray<APiece*> newUnlockedPieces;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		bool isGameWon = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		EGameMode currentGameMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		int totalStageNum = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		int currentStage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TArray<UCSStage*> allStages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TArray<UPower*> currentAllPowers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<FName> playerSelectedPieceNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		int currentEnemiesKilledCount = 0;

	// to initialize
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TSubclassOf<UPieceGenerator> PieceGeneratorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TSubclassOf<UPieceAbilityGenerator> PieceAbilityGeneratorClass;

public:
	virtual void Init() override;
	
	virtual void Shutdown() override;

	UFUNCTION(BlueprintCallable, Category = "Save Data")
		void loadSaveData();
	UFUNCTION(BlueprintCallable, Category = "Save Data")
		void setSaveData();

	UFUNCTION(BlueprintCallable, Category = "Level Control")
		void loadGameModeAttributes();
	UFUNCTION(BlueprintCallable, Category = "Level Control")
		void loadGameModeAttributesDirect(ACSGameMode* currentCSGameMode);

	UFUNCTION(BlueprintCallable, Category = "Level Control")
		void openNextLevel(EGameMode nextGameMode);


	UFUNCTION(BlueprintCallable, Category = "Pieces Control")
		void resetAllPieces();
	UFUNCTION(BlueprintCallable, Category = "Pieces Control")
		void createInitUnloackedPieces();
	UFUNCTION(BlueprintCallable, Category = "Pieces Control")
		void InitPowerPieces();

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setIsFirstTimeOpening(bool gameStatus);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		bool getIsFirstTimeOpening();

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setGameLanguage(ELanguage aLanguage);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		ELanguage getGameLanguage();

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setIsLastGameFinished(bool gameStatus);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		bool getIsLastGameFinished();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setCurrentDifficulty(int aDifficulty);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		int getCurrentDifficulty();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setUnlockedPieces(TArray<APiece*> pieces);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<APiece*> getUnlockedPieces();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setIsGameWon(bool gameState);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		bool getIsGameWon();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setCurrentPowers(TArray<UPower*> allPowers);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<UPower*> getCurrentPowers();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setStageNum(int stageNum);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		int getStageNum();

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setCurrentStageNum(int aCurrentStage);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		int getCurrentStageNum();

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setAllStages(TArray<UCSStage*> allGeneratedStages);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<UCSStage*> getAllStages();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setTotalEnemiesKilled(int killCount);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		int getTotalEnemiesKilled();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setNewUnlockedPieces(TArray<APiece*> pieces);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<APiece*> getNewUnlockedPieces();
};
