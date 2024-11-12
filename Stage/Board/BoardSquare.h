// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../CSCommonType.h"
#include "BoardSquare.generated.h"

// forward declaration
class APiece;

UCLASS(Blueprintable)
class ABoardSquare : public AActor
{
	GENERATED_BODY()

public:
	ABoardSquare();

protected:
	// square basic info
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		ETerrain squareTerrain;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USceneComponent* squareScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic Info")
		class UStaticMeshComponent* squareBody;

	// square gameplay stats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		FLocation inBoardLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		int sideSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		int height;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		bool isAccessible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		bool canBeReached; /*if the square is in the selected piece move range*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		bool isRevealed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		bool isOccupied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		APiece* occupiedPiece;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		int squareValue; /*ai control calculation*/

public:
	// square gameplay stats method
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setInBoardLocation(int x, int y);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		FLocation getInBoardLocation();


	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setSideSize(int aValue);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		int getSideSize();


	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setIsAccessible(bool squareAccessState);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		bool getIsAccessible();


	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setCanBeReached(bool reachable);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		bool getCanBeReached();

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void canReachedEffect();

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void canNotReachedEffect();


	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setIsRevealed(bool squareRevealState);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		bool getIsRevealed();


		// kill the square no matter what if is occupied
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setIsOccupied(UBoard* missionBoard, APiece* aNewPiece);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		bool getIsOccupied();

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		APiece*& getOccupiedPiece();

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		virtual void occupiedEffect(APiece* aNewPiece);
	
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void swapOccupiedPieces(ABoardSquare* anotherSquare);


	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setSquareValue(int aValue);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		int getSquareValue();

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void updateSquareValue(int modifier);
};
