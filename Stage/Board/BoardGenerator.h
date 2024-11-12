// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// all board square
#include "BoardSquare.h"
#include "LandSquare.h"
#include "OceanSquare.h"
#include "MountainSquare.h"

#include "BoardGenerator.generated.h"

UCLASS(Blueprintable)
class UBoardGenerator : public UObject
{
	GENERATED_BODY()

public:
	UBoardGenerator();

protected:
	// board length
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		int lengthNoise = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		int stageOneBoardLength = 18;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		int stageTwoBoardLength = 27;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		int stageThreeBoardLength = 36;

	// perlin parameters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		float perlinScale = 0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		float perlinMinThreshold = -0.2f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		float perlinMaxThreshold = -0.2f;

	// recognize all squares
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		TSubclassOf<class ALandSquare> landSquareClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		TSubclassOf<class AOceanSquare> oceanSquareClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board Generation Stats")
		TSubclassOf<class AMountainSquare> mountainSquareClass;

public:
	UFUNCTION(BlueprintCallable, Category = "Board Generation")
		UBoard* generateBoard(UCSMission* boardOwner, int currentStage);

	UFUNCTION(BlueprintCallable, Category = "Board Generation")
		int getRandomBoardLength(int currentStage);

	UFUNCTION(BlueprintCallable, Category = "Board Generation")
		ABoardSquare* getSquareByNoiseValue(int noiseValue);

	UFUNCTION(BlueprintCallable, Category = "Board Generation")
		ABoardSquare* generateLandSquare();

	UFUNCTION(BlueprintCallable, Category = "Board Generation")
		ABoardSquare* generateOceanSquare();

	UFUNCTION(BlueprintCallable, Category = "Board Generation")
		ABoardSquare* generateMountainSquare();
};
