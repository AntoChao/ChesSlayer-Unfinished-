// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "../PieceAbility.h"
#include "PieceAbilityMove.generated.h"

UCLASS()
class UPieceAbilityMove : public UPieceAbility
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int abilityDetectDistance = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int abilityDistance = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int specificAbilityDistance = 0;

	// direction distance change (for more specific calculations)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int upDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int downDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int leftDistance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int rightDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool targetInUp = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool targetInDown = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool targetInLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool targetInRight = false;

public:
	UPieceAbilityMove();

	virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation, 
		UBoard*& missionBoard, UBoard*& revealedBoard) override;

	// specific directional function
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void checkIfTargetOnHorizontal(FLocation pieceLocation, FLocation targetLocation);
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void checkIfTargetOnVertical(FLocation pieceLocation, FLocation targetLocation);

	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void resetAllDirectionVariables();
	UFUNCTION(BlueprintCallable, Category = "Square Gameplay Method")
		void setAllDirectionDistance();
};