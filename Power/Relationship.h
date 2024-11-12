// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "../CSCommonType.h"
#include "Relationship.generated.h"

UCLASS()
class URelationship : public UObject
{
	GENERATED_BODY()

public:
	URelationship();

protected:

	/** relationship is measure as a integer
	[-inf, -1] -> enemy
	[-1, 1] -> neutro
	[1, +inf]
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relationship Properties")
		int NeutroMin = -1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relationship Properties")
		int NeutroMax = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relationship Properties")
		int relationWithPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relationship Properties")
		int relationWithEmpire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relationship Properties")
		int relationWithBandit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Relationship Properties")
		int relationWithForeiger;

public:
	// relationship methods
	UFUNCTION(BlueprintCallable, Category = "Ally/ Enemy")
		ERelationship getRelationship(EPowerName thePowerName);

	UFUNCTION(BlueprintCallable, Category = "Ally/ Enemy")
		ERelationship getPlayerRelationship();

	UFUNCTION(BlueprintCallable, Category = "Ally/ Enemy")
		ERelationship getEmpireRelationship();

	UFUNCTION(BlueprintCallable, Category = "Ally/ Enemy")
		ERelationship getBanditRelationship();

	UFUNCTION(BlueprintCallable, Category = "Ally/ Enemy")
		ERelationship getForeigerRelationship();

	// Update values
	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		void updateRelationWithPlayer(int value);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		void updateRelationWithEmpire(int value);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		void updateRelationWithBandit(int value);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		void updateRelationWithForeiger(int value);

	// Setter & Getter
	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		void setRelationWithPlayer(int value);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		int getRelationWithPlayer();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		void setRelationWithEmpire(int value);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		int getRelationWithEmpire();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		void setRelationWithBandit(int value);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		int getRelationWithBandit();


	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		void setRelationWithForeiger(int value);

	UFUNCTION(BlueprintCallable, Category = "Setter & Getter")
		int getRelationWithForeiger();
};
