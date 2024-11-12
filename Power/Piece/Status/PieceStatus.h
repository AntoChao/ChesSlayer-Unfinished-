// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// piece
// #include "../Piece.h"

#include "PieceStatus.generated.h"

// forward declaration
class UPower;
class APiece;

UCLASS()
class UPieceStatus : public UObject
{
	GENERATED_BODY()

public:
	UPieceStatus();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status Stats")
		bool isPersistent;

	// should have owner power for simplity like mark -> reveal map
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status Stats")
		UPower* owner = nullptr;

public:
	UFUNCTION(BlueprintCallable, Category = "Status Method")
		void setIfIsPersistent(bool state);

	UFUNCTION(BlueprintCallable, Category = "Status Method")
		bool getIfIsPersistent();

	UFUNCTION(BlueprintCallable, Category = "Status Method")
		void applyStatus(APiece* aPiece);
};