// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityPetStep.generated.h"

UCLASS()
class UAbilityPetStep : public UPieceAbilityMove
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		APiece* petPiece = nullptr;

public:
	UAbilityPetStep();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	UFUNCTION(BlueprintCallable, Category = "Ability Method")
		void setPetPiece(APiece* aPetPiece);


};