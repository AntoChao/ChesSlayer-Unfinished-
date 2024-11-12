// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "../../../CSCommonType.h"

#include "PieceAbility.generated.h"

UCLASS()
class UPieceAbility : public UObject
{
	GENERATED_BODY()

public:
	UPieceAbility();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		EAbilityName abilityNameEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		FName abilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		EAbilityType abilityType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		class UTexture2D* abilityImage;

	// ability property
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool isUnique = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int chargeNum = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int energyCost = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		int movePointCost = 1;


	// ability direction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		EAbilityDirection abilityXDirection = EAbilityDirection::ENone;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		EAbilityDirection abilityYDirection = EAbilityDirection::ENone;


	// process to be activate
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool isSelected = false; /*ability be selected, reveal all target square*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool isTargetChecked = false; /*check target location or target piece*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Ability")
		bool isControledTargetChecked = false; /*check target location of the control piece*/

public:
	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		void setAbilityName(FName anAbilityName);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		FName getAbilityName();


	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		void setAbilityType(EAbilityType aAbilityType);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		EAbilityType getAbilityType();


	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		void setIsUnique(bool uniqueness);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		bool getIfIsUnique();


		// ability direction
	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		void setAbilityDirection(FLocation pieceLocation, FLocation targetLocation);
	
	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		FLocation getNewLocationByDirection(FLocation pieceLocation, int moveDistance);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		EAbilityDirection getReverseDirection(EAbilityDirection aDirection);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		EAbilityDirection getOmniDirection();


	// for passive ability
	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		virtual void equipAbilityEffect(APiece*& owner);
	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		virtual void unequipAbilityEffect(APiece*& owner);


	// for active ability
	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		void activate(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		virtual void isSelectedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		virtual void isTargetCheckedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		virtual void isControledTargetCheckedEffect(APiece*& owner, FLocation targetLocation, UBoard*& missionBoard, UBoard*& revealedBoard);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		virtual void abilityFinishedEffect(APiece*& owner);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		virtual bool isAbilityAvailable(APiece*& owner);

	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		void turnResetAbility();

		// reset charges, or ability decision in mission
	UFUNCTION(BlueprintCallable, Category = "Piece Ability Method")
		virtual void missionResetAbility();

};