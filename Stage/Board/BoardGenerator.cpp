// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoardGenerator.h"
#include "Math/UnrealMathUtility.h"

UBoardGenerator::UBoardGenerator() {

}

UBoard* UBoardGenerator::generateBoard(UCSMission* boardOwner, int currentStage) {
	int boardHeight = this->getRandomBoardLength(currentStage);
	int boardWidth = this->getRandomBoardLength(currentStage);

    UBoard* board = NewObject<UBoard>(boardOwner);
    
    board->setBoardSize(boardHeight, boardWidth);
    
    int totalSize = boardHeight * boardWidth;

    FRandomStream RandomStream(FDateTime::Now().GetMillisecond());
    float perlinSeed = RandomStream.FRand(); // Random seed for Perlin noise

    for (int Y = 0; Y < boardHeight; Y++) {
        for (int X = 0; X < boardWidth; X++) {
            float noiseValue = FMath::PerlinNoise2D(FVector2D(X, Y) * perlinScale + perlinSeed);
            ABoardSquare* newSquare = this->getSquareByNoiseValue(noiseValue);
            newSquare->setInBoardLocation(X, Y);

            board->addSquare(newSquare);
        }
    }

    return board;
}

int UBoardGenerator::getRandomBoardLength(int currentStage) {
    int noise = lengthNoise * currentStage;
    switch (currentStage) {
    case 1: {
        return FMath::RandRange(stageOneBoardLength - noise, stageOneBoardLength + noise);
    }
    case 2: {
        return FMath::RandRange(stageTwoBoardLength - noise, stageTwoBoardLength + noise);
    }
    case 3: {
        return FMath::RandRange(stageThreeBoardLength - noise, stageThreeBoardLength + noise);
    }
    default:
        return 0;
    }
}

ABoardSquare* UBoardGenerator::getSquareByNoiseValue(int noiseValue) {
    if (noiseValue < perlinMinThreshold) {
        return generateOceanSquare();
    }
    else {
        if (noiseValue > perlinMaxThreshold) {
            return generateLandSquare();
        }
        else {
            return generateMountainSquare();
        }
    }
}

ABoardSquare* UBoardGenerator::generateLandSquare() {
    return Cast<ABoardSquare>(GetWorld()->SpawnActor<ALandSquare>(landSquareClass, FVector::ZeroVector, FRotator::ZeroRotator));
}

ABoardSquare* UBoardGenerator::generateOceanSquare() {
    return Cast<ABoardSquare>(GetWorld()->SpawnActor<AOceanSquare>(oceanSquareClass, FVector::ZeroVector, FRotator::ZeroRotator));
}

ABoardSquare* UBoardGenerator::generateMountainSquare() {
    return Cast<ABoardSquare>(GetWorld()->SpawnActor<AMountainSquare>(mountainSquareClass, FVector::ZeroVector, FRotator::ZeroRotator));
}