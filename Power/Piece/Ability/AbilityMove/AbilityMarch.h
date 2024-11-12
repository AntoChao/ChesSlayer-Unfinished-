// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PieceAbilityMove.h"
#include "AbilityMarch.generated.h"

UCLASS()
class UAbilityMarch : public UPieceAbilityMove
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		EAbilityDirection lastMarchDirection = EAbilityDirection::ENone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Square Attribute")
		int currentSpeed;

public:
	UAbilityMarch();

	virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard) override;
	
	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		void updateCurrentSpeed(FLocation pieceLocation, FLocation targetLocation);

	virtual void missionResetAbility() override;
};