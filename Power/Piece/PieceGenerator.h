// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"

#include "Piece.h"

#include "PieceGenerator.generated.h"

UCLASS(Blueprintable)
class UPieceGenerator : public UObject
{
	GENERATED_BODY()

public:
	UPieceGenerator();

	static UPieceGenerator* GetPieceGeneratorInstance();
	
	static void SetPieceGeneratorClass(TSubclassOf<UPieceGenerator> NewClass);

protected:
	
	// Static instance of the singleton
	static UPieceGenerator* SingletonPieceGeneratorInstance;

	// Default class to spawn, can be set via Blueprint
	static TSubclassOf<UPieceGenerator> PieceGeneratorClass;


	FActorSpawnParameters SpawnParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Name")
		int totalPiecesNum = 27;

	// recognize all tsubclasses

	// empire classes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Name")
		int totalEmpirePiecesNum = 13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> pawnClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> kingClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> rookClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> knightClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> bishopClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> queenClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> cannonClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> warriorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> doctorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> guardClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> catapultClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> priestClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> archeryClass;

	// bandit classes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Name")
		int totalBanditPiecesNum = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> rangerClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> assassinClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> thiefClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> beastMasterClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> doggyClass;

	// foreiger classes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Name")
		int totalForeigerPiecesNum = 9;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> mageClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> samuraiClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> cultistClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> cowboyClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> bountyHunterClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> werewolfClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> witchClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> ninjaClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece TSubclass")
		TSubclassOf<APiece> prisonerClass;

public:
	UFUNCTION(BlueprintCallable, Category = "Generator Method")
		APiece* generateSpecificPieceByName(UWorld* World, FName pieceName);

	UFUNCTION(BlueprintCallable, Category = "Generator Method")
		APiece* generateRandomPiece(UWorld* World);
	UFUNCTION(BlueprintCallable, Category = "Generator Method")
		APiece* generateEmpirePiece(UWorld* World);
	UFUNCTION(BlueprintCallable, Category = "Generator Method")
		APiece* generateBanditPiece(UWorld* World);
	UFUNCTION(BlueprintCallable, Category = "Generator Method")
		APiece* generateForeigerPiece(UWorld* World);

};
