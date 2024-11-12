// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CSGameMode.h"

// mission
#include "../Stage/CSMission.h"

#include "GameplayGameMode.generated.h"

UCLASS(Blueprintable)
class AGameplayGameMode : public ACSGameMode
{
	GENERATED_BODY()

public:
	AGameplayGameMode();

	virtual void BeginPlay() override;

protected:
	virtual void loadInstanceAttributes() override;
	virtual void updateInstance() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		int gameDifficulty; /*current stage already defined*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		TArray<APiece*> unlockedPieces; /*current stage already defined*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		bool isGameWon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		int totalStage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		int currentStageNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		TArray<UCSStage*> allStages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		TArray<UPower*> allPower;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Common Values")
		TArray<APiece*> newUnlockedPieces;


public:
	UFUNCTION(BlueprintCallable, Category = "Gameplay GameMode Method")
		void finishCurrentStage();

	UFUNCTION(BlueprintCallable, Category = "Gameplay GameMode Method")
		void startNextStage();

	UFUNCTION(BlueprintCallable, Category = "Gameplay GameMode Method")
		void selectMission();
};



