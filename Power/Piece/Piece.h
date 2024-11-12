// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// piece stats
#include "Sound/SoundCue.h"

#include "Status/PieceStatus.h"

// abilities
#include "Ability/PieceAbilityGenerator.h"
#include "Ability/PieceAbility.h"

#include "Piece.generated.h"

// foward declaration
class APower;
class ABoardSquare;

UCLASS(Blueprintable)
class APiece : public AActor
{
	GENERATED_BODY()

public:
	APiece();

protected:
	// piece basic info attribute
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Info")
		int pieceID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Info")
		FName pieceName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Info")
		FText pieceNameEnlish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Info")
		FText pieceNameChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Info")
		FText pieceNameSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		int rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Info")
		class UTexture2D* pieceImage;

		// body
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		class USceneComponent* pieceScene;

	UPROPERTY(EditAnywhere, Category = "Piece Info")
		class UStaticMeshComponent* pieceBody;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Info")
		USoundCue* pieceSelectedSound;

	// piece basic stats attribute
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		UPower* powerBelong;

		// select the most important piece for assassin, it depends on the survived time
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		bool isArmyLeader;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		int survivedTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		int viewPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		int movePoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		int currentMovePoint;

	/* energy Point 
		- determinate the powers turn order, update each turn
		- cost of powerful ability
		- determinate the power leader
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		int energyPoint; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		int currentEnergyPoint;

	// status
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		TSet<UPieceStatus*> allStatus;

	// ability generator
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		TSubclassOf<class UPieceAbilityGenerator> abilityGeneratorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		UPieceAbilityGenerator* abilityGenerator = nullptr;*/

	// ability
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		EAbilityName initDefaultAbilityName = EAbilityName::ENone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		EAbilityName initAbilityOneName = EAbilityName::ENone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		EAbilityName initAbilityTwoName = EAbilityName::ENone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		UPieceAbility* defaultAbility = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		UPieceAbility* abilityOne = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		UPieceAbility* abilityTwo = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Piece Stats")
		EAbilitySelected lastUsedAbility = EAbilitySelected::ENone;

	// piece mission attribute
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Attribute")
		bool isSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Attribute")
		bool isAlive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Attribute")
		ABoardSquare* pieceSquare;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Attribute")
		bool isCaptureable; /*instead of die*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Attribute")
		APiece* captureOwner; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Attribute")
		bool isWaitingForRescue = false;

public:
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void initPiece(UPower*& aPower);

	// piece basic stats methods
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		FName getPieceName();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setPowerBelong(UPower*& aPower);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		UPower* getPowerBelong();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		bool isSamePower(APiece* anotherPiece);
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		bool isAllyPower(APiece* anotherPiece);
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		bool isNeutroPower(APiece* anotherPiece);
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		bool isEnemyPower(APiece* anotherPiece);

		// select the army leader
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setIsArmyLeader(bool state);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		bool getIfIsArmyLeader();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setSurvivedTime(int aNum);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		int getSurvivedTime();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void updateSurvivedTime(int modifier);


	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setViewPoint(int aNewValue);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		int getViewPoint();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void updateViewPoint(int modifier);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void updateFogOfWar(UBoard*& revealedBoard);


	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setMovePoint(int aNewValue);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		int getMovePoint();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void updateMovePoint(int modifier);


	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setCurrentMovePoint(int aNewValue);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		int getCurrentMovePoint();

		// I suppose that every action will cost MovePoint
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void updateCurrentMovePoint(int modifier);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void resetCurrentMovePoint();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void completedOneAction();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void noMovePointLeftEffect();


	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setEnergyPoint(int aNewValue);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		int getEnergyPoint();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void updateEnergyPoint(int modifier);


	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setCurrentEnergyPoint(int aNewValue);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		int getCurrentEnergyPoint();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void updateCurrentEnergyPoint(int modifier);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void resetCurrentEnergyPoint();


		// status
	UFUNCTION(BlueprintCallable, Category = "Status Method")
		void resetAllStatus();

	/** there may have status that persist through missions
	* eliminate all status that do not persist missions, that are "temporary"
	*/
	UFUNCTION(BlueprintCallable, Category = "Status Method")
		void resetTemporaryStatus();

	UFUNCTION(BlueprintCallable, Category = "Status Method")
		void addStatus(UPieceStatus* aStatus);

	UFUNCTION(BlueprintCallable, Category = "Status Method")
		void removeStatus(UPieceStatus* aStatus);

	/** ??? */
	UFUNCTION(BlueprintCallable, Category = "Status Method")
		void applyAllStatus();


		// ability methods
	/*
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void initializeAbilityGenerator();*/

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void initializeAllAbilities();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setDefaultAbility(UPieceAbility* aAbility);
	
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		UPieceAbility* getDefaultAbility();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setAbilityOne(UPieceAbility* aAbility);
	
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		UPieceAbility* getAbilityTwo();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setAbilityTwo(UPieceAbility* aAbility);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		UPieceAbility* getAbilityOne();

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		bool isSettingSameAbility(UPieceAbility* aAbility, 
			UPieceAbility* anotherAbility); /*One piece can not have 2 same ability*/

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void swapAbilityOneTwo();


	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void setLastAbilityUsed(EAbilitySelected anAbility);

	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		EAbilitySelected getLastAbilityUsed();
	// piece mission methods
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsSelected(bool pieceState);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool getIsSelected();

		// should be Blueprint function?
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void selectedEffect();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void unselectedEffect();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsAlive(bool pieceState);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool getIsAlive();


	// set piece location
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setPieceSquare(ABoardSquare* aSquare);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		ABoardSquare* getPieceSquare();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsWaitingForRescue(bool state);
	
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool getIsWaitingForRescue();

	/** piece is available if 
	* has current movepoint left
	* is not affected by "stun" status
	*/
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		bool isPieceAvailable();

	/** piece state at the initial of each mission:
	* is alive
	* reset current move point
	* eliminate all status (not sure)
	*/
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void initializePieceState();

	/** piece go to the next turn, it needs to update:
	* reset current move point
	* apply status
	*/
	UFUNCTION(BlueprintCallable, Category = "Stats Method")
		void updatePieceState();

	/** getKilled function
	* input: received the killer Piece
	* effect:
	*	modify relationship
	*	gain experience ???
	*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void getKilled(APiece*& killerPiece);


	/*for player control*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void receiveCommand(FLocation targetLocation, UBoard*& missionBoard,
			UBoard*& revealedBoard);

	/*for ai control*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void calculateInBoardValues(UBoard*& missionBoard, UBoard*& revealedBoard);


	/*each ability just turn square to available*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void selectDefaultAbility(FLocation targetLocation, UBoard*& missionBoard, 
			UBoard*& revealedBoard);
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void selectAbilityOne(FLocation targetLocation, UBoard*& missionBoard,
			UBoard*& revealedBoard);
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void selectAbilityTwo(FLocation targetLocation, UBoard*& missionBoard,
			UBoard*& revealedBoard);

		// show ability can not be selected in UI
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsAbilityCanBeSelected(bool aState);

};
