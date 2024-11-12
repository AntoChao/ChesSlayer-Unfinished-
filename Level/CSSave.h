// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "../Power/Piece/Piece.h"

#include "../Stage/CSMission.h"
#include "../Stage/CSStage.h"

#include "CSSave.generated.h"

UCLASS(Blueprintable)
class UCSSave: public USaveGame
{
	GENERATED_BODY()

public:
	UCSSave();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		ELanguage language = ELanguage::EEnglish;

	// Player History
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		int lastTimeDifficulty = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<APiece*> alreadyUnlockedPieces;

	// if player exit in the middle game

	/*The init game read this to know if enable "Continue"
	  Only true if player finish the game (get in postgame)*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		bool isNewGame = false; 

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<APiece*> playerInitPieces;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<APiece*> currentUnlockedPieces; /*Correspond to the newUnlockedPieces*/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<UPower*> lastTimePowers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		int totalStageNum = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		int lastTimeStage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<UCSStage*> allStages;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		int lastTimeEnemiesKilledCount = 0;

public:
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setLanguage(ELanguage aLanguage);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		ELanguage getLanguage();

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setLastTimeDifficulty(int aDifficulty);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		int getLastTimeDifficulty();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setAlreadyUnlockedPieces(TArray<APiece*> pieces);
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<APiece*> getAlreadyUnlockedPieces();


	// if player exit in the middle game
	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setIsNewGame(bool status);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		bool getIsNewGame();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setPlayerInitPieces(TArray<APiece*> pieces);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<APiece*> getPlayerInitPieces();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setCurrentUnlockedPieces(TArray<APiece*> pieces);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<APiece*> getCurrentUnlockedPieces();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setLastTimeAllPowers(TArray<UPower*> powers);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<UPower*> getLastTimeAllPowers();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setStageNum(int aStageNum);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		int getStageNum();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setLastTimeStage(int stage);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		int getLastTimeStage();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setAllStages(TArray<UCSStage*> stages);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		TArray<UCSStage*> getAllStages();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		void setLastTimeEnemyKilledCount(int count);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getters")
		int getLastTimeEnemyKilledCount();
};
