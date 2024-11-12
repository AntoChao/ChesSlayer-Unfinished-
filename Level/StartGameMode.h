// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CSGameMode.h"
#include "../Power/PlayerPower.h"
#include "../Power/AIPowers/AIPower.h"

// all powers
#include "StartGameMode.generated.h"

UCLASS(Blueprintable)
class AStartGameMode : public ACSGameMode
{
	GENERATED_BODY()

public:
	AStartGameMode();

	virtual void BeginPlay() override;

protected:
	virtual void loadInstanceAttributes() override;
	virtual void updateInstance() override;

	// game values to initialize
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		int gameDifficulty = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		int startStageNum = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		int initMaxEnergy = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TArray<APiece*> unlockedPieces;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		TArray<APiece*> selectedPieces = {};

	// initialization all powers function
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers Initialization")
		TArray<UPower*> allPower;

	UFUNCTION(BlueprintCallable, Category = "Powers Initialization")
		void CreateAllPowers();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		TSubclassOf<UPower> playerPowerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		TSubclassOf<UPower> empirePowerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		TSubclassOf<UPower> banditPowerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		TSubclassOf<UPower> foreigerPowerClass;

	// initialization all stages 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers Initialization")
		TArray<UCSStage*> allStages;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Powers Initialization")
		UCSStage* currentStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Powers Initialization")
		TSubclassOf<UCSStage> stageClass;

	UFUNCTION(BlueprintCallable, Category = "Stages Initialization")
		void CreateAllStages();

	UFUNCTION(BlueprintCallable, Category = "Stages Initialization")
		void InitStage(int aStageNum);

public:
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		void setGameDifficulty(int difficulty);
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		int getGameDifficulty();

	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		void setInitMaxEnergy(int maxEnergy);
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		int getInitMaxEnergy();
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		void updateInitMaxEnergy(int modifier);

	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		void setUnlockedPieces(TArray<APiece*> allUnlockedPieces);

	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		void setSelectedPieces(TArray<APiece*> allSelectedPieces);
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		TArray<APiece*> getSelectedPieces();
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		bool ableToAddAPiece(APiece* aPiece);
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		int getTotalEnergy(TArray<APiece*> aPiece);
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		void addASelectedPiece(APiece* aPiece);
	UFUNCTION(BlueprintCallable, Category = "Common Values Method")
		void removeASelectedPiece(APiece* aPiece);
};



