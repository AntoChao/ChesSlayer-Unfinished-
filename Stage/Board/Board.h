// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BoardSquare.h"

#include "Board.generated.h"

UCLASS(Blueprintable)
class UBoard : public UObject
{
	GENERATED_BODY()

public:
	UBoard();

protected:
	// square basic info
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Board Info")
		int numRow;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Basic Board Info")
		int numColumn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Board Info")
		TArray<ABoardSquare*> allBoardSquares;

public:
	// square gameplay stats method
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setBoardSize(int height, int width);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		int getBoardHeight();

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		int getBoardWidth();

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		TArray<ABoardSquare*>& getAllSquares();
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void addSquare(ABoardSquare* aSquare);


	// board square
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		ABoardSquare*& getBoardSquareAtLocation(FLocation aLocation);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		bool isBoardSquareValid(FLocation aLocation);

		// take account of the place has to be accessible
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setBoardSquareReachable(FLocation targetLocation);

		// ignore if the place has to be accessible or not
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setBoardSquareReachableNotChecking(FLocation targetLocation);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		bool isBoardSquareValidToMove(FLocation aLocation);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		ABoardSquare*& getNearBySquare(FLocation aLocation);


		// pieces
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void getAllSamePowerPieces(TArray<APiece*>& samePowerPieces, APiece*& onePiece);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		APiece* getRandomPieceOnBoard();

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void pushPieceXDistance(FLocation initLocation, EAbilityDirection toPushDirection, int specificAbilityDistance);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		bool pushPiece(FLocation initLocation, EAbilityDirection toPushDirection);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		FLocation getRelativeDirection(EAbilityDirection aDirection);

	// reachability
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setBoardSquareReachability(FLocation aLocation);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void resetBoardSquareReachability();

	// value
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setBoardSquareValue(FLocation aLocation, int aValue);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void resetBoardSquareValues();

};
