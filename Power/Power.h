// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "../CSCommonType.h"

// piece
#include "Piece/PieceGenerator.h"


// relation
#include "Relationship.h"

// mission
#include "../Stage/Board/Board.h"
#include "../Stage/Board/BoardSquare.h"

#include "Power.generated.h"

// forward declaration
class APiece;
class UCSMission;

UCLASS(Blueprintable)
class UPower : public UObject
{
	GENERATED_BODY()

public:
	UPower();

protected:

	// power common properties
		// army
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		EPowerName powerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int armyDefaultNoise = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int armyMaxEnergy = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int currentArmyEnergy = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int armyRemainingEnergy = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		TArray<FName> armyNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		TArray<APiece*> army;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		APiece* armyLeader;

		// relation
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		URelationship* relationships;

		/*the initial relationship between each power*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int initPlayerRelation = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int initEmpireRelation = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int initBanditRelation = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int initForeigerRelation = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		int initRelationNoise = 2;

	 // in mission properties
		/*reveal board is just for view and square value*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		UCSMission* currentMission = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		UBoard* revealedBoard; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		FLocation initLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		bool isReadyToEndTurn;

		/*power is the entity that is in charge of manipulating piece*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		APiece* currentSelectedPiece = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		APiece* pieceMoved = nullptr; /*ensure that player not move more than 1 piece per turn*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		APiece* currentInspectedPiece = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Properties")
		ABoardSquare* currentInspectedSquare = nullptr;

public:
	UFUNCTION(BlueprintCallable, Category = "Initialize")
		virtual void InitPower(int aDifficulty, int currentStage, TArray<APiece*> selectedPieces);

	// common methods
	UFUNCTION(BlueprintCallable, Category = "Common Method")
		int getNoisedValue(int value, int noise);

	UFUNCTION(BlueprintCallable, Category = "Common Method")
		EPowerName getPowerName();

	// army methods
	/* startGameMode will determinates the number of pieces based on difficulty*/
	UFUNCTION(BlueprintCallable, Category = "Army Method")
		virtual void setMaxArmyEnergy(int difficulty, int currentStage);

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		int getArmyMaxEnergy();

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void updateMaxArmyEnergy(int modifier);

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void updateCurrentAmryEnergy(int modifier);

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		int getArmyCurrentEnergy();

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void calculateRemaningArmyEnergy();


	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void initializeArmyPiecesByName();

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void saveArmyPiecesInName();
	
	UFUNCTION(BlueprintCallable, Category = "Army Method")
		bool isAbleToAddPiece(APiece* pieceToAdd);

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void fillArmyByRandom(); /*if current size != default size, refill the army*/

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		TArray<APiece*> getArmy();

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void addArmyPiece(APiece*& newPiece);

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void removeArmyPiece(APiece*& pieceToRemove);

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		APiece* recruitSpecificPieceByName(FName pieceName);
	UFUNCTION(BlueprintCallable, Category = "Army Method")
		APiece* recruitRandomPiece();

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		void selectLeader();

	UFUNCTION(BlueprintCallable, Category = "Army Method")
		APiece* getArmyLeader();

	// relationship methods
	UFUNCTION(BlueprintCallable, Category = "Relationship Method")
		void initializeRelationship();

	UFUNCTION(BlueprintCallable, Category = "Relationship Method")
		URelationship* getRelationship();

	UFUNCTION(BlueprintCallable, Category = "Relationship Method")
		void updateRelation(EPowerName thePowerName, int value);

	// mission method
		/*should set per mission*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setRevealedBoard(UBoard* currentBoard); 

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		UBoard* getRevealedBoard();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setInitLocation(FLocation aLocation);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		FLocation getInitLocation();


		// power turn control
	/** Each power only move 1 piece per turn */
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		virtual void locateInitPieces(); /*put pieces around initial location*/

	/** isOkayToEndTurn act differently for player and ai
	* player: if player want to end turn, the turn ends
	* ai: if ai want to end turn or have no available piece then end turn
	*/
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		virtual bool isOkayToEndTurn();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool stillHaveAvailablePiece();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setIsReadyToEndTurn(bool aNewState);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		bool getIsReadyToEndTurn();

		// power turn action
	/** The process of player for taking an action on piece
	* player's click is pointed to a FLocation on board -> reactBoardInput(FLocation)
	* if player had already selected a piece
	*	check if this FLocation is accessible and canBeReached
	*		yes then piece->receiveCommand(FTargetLocation, missionboard, revealedboard), piece should know which ability was selected
	*		no then unselect the piece
	* else if player hasnt selected a piece yet
	*	check if this FLocation has a piece
	*		check if the piece is in player army
	*			select this piece
	*/

	/** The process of ai power for taking an action on piece
	* target piece & target location
	* use min-max to calculate all square values by considering all possible move on the revealed board
	*	piece->calculateValues(missionboard, revealedboard)
	* select the piece wich max values and do the 
	*/
	
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		virtual void startTurn(UCSMission*& aCurrentMission);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		virtual void endAction();

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		virtual void endTurn();

		// player
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void reactPlayerInput(FLocation targetLocation, UBoard*& missionBoard);


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setCurrentSelectedPiece(APiece*& aPiece);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void unsetCurrentSelectedPiece();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setCurrentInspectedPiece(APiece*& aPiece);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void unsetCurrentInspectedPiece();


	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void setCurrentInspectedSquare(ABoardSquare* aSquare);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void unsetCurrentInspectedSquare();

		// ai
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void calculateAllBoardValues(FLocation targetLocation); /*just for ai*/

		// piece ability selection
		// reset board canBeReached
	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void unselectPieceAbility(UBoard*& missionBoard);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void selectPieceDefaultAbility(FLocation targetLocation, UBoard*& missionBoard);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void selectPieceAbilityOne(FLocation targetLocation, UBoard*& missionBoard);

	UFUNCTION(BlueprintCallable, Category = "Mission Method")
		void selectPieceAbilityTwo(FLocation targetLocation, UBoard*& missionBoard);

	// mission end function
	UFUNCTION(BlueprintCallable, Category = "Mission End Method")
		virtual void missionEndEffect();

	/*inlucding the survived/leader, and upgrading*/
	UFUNCTION(BlueprintCallable, Category = "Mission End Method")
		virtual void updateArmyAfterMission();
};
