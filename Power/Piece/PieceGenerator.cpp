// Copyright Epic Games, Inc. All Rights Reserved.

#include "PieceGenerator.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"



UPieceGenerator::UPieceGenerator() {
}

UPieceGenerator* UPieceGenerator::SingletonPieceGeneratorInstance = nullptr;
TSubclassOf<UPieceGenerator> UPieceGenerator::PieceGeneratorClass = UPieceGenerator::StaticClass();

void UPieceGenerator::SetPieceGeneratorClass(TSubclassOf<UPieceGenerator> NewClass) {
	PieceGeneratorClass = NewClass;
}

UPieceGenerator* UPieceGenerator::GetPieceGeneratorInstance() {
	if (SingletonPieceGeneratorInstance == nullptr){
		// Create the singleton instance if it doesn't exist
		if (PieceGeneratorClass) {
			// SingletonInstance = NewObject<UMySingletonBase>(GetOuter(), SingletonClass);
			SingletonPieceGeneratorInstance = NewObject<UPieceGenerator>(GetTransientPackage(), PieceGeneratorClass);
			SingletonPieceGeneratorInstance->AddToRoot();
		}
	}
	return SingletonPieceGeneratorInstance;
}

APiece* UPieceGenerator::generateSpecificPieceByName(UWorld* World, FName pieceName) {
	APiece* generatedPiece = nullptr;
	if (World) {
		// empire
		if (pieceName == FName(TEXT("Pawn"))) {
			generatedPiece = World->SpawnActor<APiece>(pawnClass);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("generate a pawn piece object"));
		}
		else if (pieceName == FName(TEXT("King"))) {
			generatedPiece = World->SpawnActor<APiece>(kingClass);
		}
		else if (pieceName == FName(TEXT("Rook"))) {
			generatedPiece = World->SpawnActor<APiece>(rookClass);
		}
		else if (pieceName == FName(TEXT("Knight"))) {
			generatedPiece = World->SpawnActor<APiece>(knightClass);
		}
		else if (pieceName == FName(TEXT("Bishop"))) {
			generatedPiece = World->SpawnActor<APiece>(bishopClass);
		}
		else if (pieceName == FName(TEXT("Queen"))) {
			generatedPiece = World->SpawnActor<APiece>(queenClass);
		}
		else if (pieceName == FName(TEXT("Cannon"))) {
			generatedPiece = World->SpawnActor<APiece>(cannonClass);
		}
		else if (pieceName == FName(TEXT("Warrior"))) {
			generatedPiece = World->SpawnActor<APiece>(warriorClass);
		}
		else if (pieceName == FName(TEXT("Doctor"))) {
			generatedPiece = World->SpawnActor<APiece>(doctorClass);
		}
		else if (pieceName == FName(TEXT("Guard"))) {
			generatedPiece = World->SpawnActor<APiece>(guardClass);
		}
		else if (pieceName == FName(TEXT("Catapult"))) {
			generatedPiece = World->SpawnActor<APiece>(catapultClass);
		}
		else if (pieceName == FName(TEXT("Priest"))) {
			generatedPiece = World->SpawnActor<APiece>(priestClass);
		}
		else if (pieceName == FName(TEXT("Archery"))) {
			generatedPiece = World->SpawnActor<APiece>(archeryClass);
		}
			// bandit
		else if (pieceName == FName(TEXT("Ranger"))) {
			generatedPiece = World->SpawnActor<APiece>(rangerClass);
		}
		else if (pieceName == FName(TEXT("Assassin"))) {
			generatedPiece = World->SpawnActor<APiece>(assassinClass);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("generate an assassin piece object"));
		}
		else if (pieceName == FName(TEXT("Thief"))) {
			generatedPiece = World->SpawnActor<APiece>(thiefClass);
		}
		else if (pieceName == FName(TEXT("Beast Master"))) {
			generatedPiece = World->SpawnActor<APiece>(beastMasterClass);
		}
		else if (pieceName == FName(TEXT("Doggy"))) {
			generatedPiece = World->SpawnActor<APiece>(doggyClass);
		}
			// foreiger
		else if (pieceName == FName(TEXT("Mage"))) {
			generatedPiece = World->SpawnActor<APiece>(mageClass);
		}
		else if (pieceName == FName(TEXT("Samurai"))) {
			generatedPiece = World->SpawnActor<APiece>(samuraiClass);
		}
		else if (pieceName == FName(TEXT("Cultist"))) {
			generatedPiece = World->SpawnActor<APiece>(cultistClass);
		}
		else if (pieceName == FName(TEXT("Cowboy"))) {
			generatedPiece = World->SpawnActor<APiece>(cowboyClass);
		}
		else if (pieceName == FName(TEXT("Bounty Hunter"))) {
			generatedPiece = World->SpawnActor<APiece>(bountyHunterClass);
		}
		else if (pieceName == FName(TEXT("Werewolf"))) {
			generatedPiece = World->SpawnActor<APiece>(werewolfClass);
		}
		else if (pieceName == FName(TEXT("Witch"))) {
			generatedPiece = World->SpawnActor<APiece>(witchClass);
		}
		else if (pieceName == FName(TEXT("Ninja"))) {
			generatedPiece = World->SpawnActor<APiece>(ninjaClass);
		}
		else if (pieceName == FName(TEXT("Prisoner"))) {
			generatedPiece = World->SpawnActor<APiece>(prisonerClass);
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("pieceName cannot match any name"));
		}
	}
	return generatedPiece;
}


APiece* UPieceGenerator::generateRandomPiece(UWorld* World) {
	APiece* generatedPiece = nullptr;

	if (World) {
		int aRandomNum = FMath::FRandRange(1, totalPiecesNum);
		switch (aRandomNum) {
		// empire
		case 1:
			generatedPiece = World->SpawnActor<APiece>(pawnClass);
			break;
		case 2:
			generatedPiece = World->SpawnActor<APiece>(kingClass);
			break;
		case 3:
			generatedPiece = World->SpawnActor<APiece>(rookClass);
			break;
		case 4:
			generatedPiece = World->SpawnActor<APiece>(knightClass);
			break;
		case 5:
			generatedPiece = World->SpawnActor<APiece>(bishopClass);
			break;
		case 6:
			generatedPiece = World->SpawnActor<APiece>(queenClass);
			break;
		case 7:
			generatedPiece = World->SpawnActor<APiece>(cannonClass);
			break;
		case 8:
			generatedPiece = World->SpawnActor<APiece>(warriorClass);
			break;
		case 9:
			generatedPiece = World->SpawnActor<APiece>(doctorClass);
			break;
		case 10:
			generatedPiece = World->SpawnActor<APiece>(guardClass);
			break;
		case 11:
			generatedPiece = World->SpawnActor<APiece>(catapultClass);
			break;
		case 12:
			generatedPiece = World->SpawnActor<APiece>(priestClass);
			break;
		case 13:
			generatedPiece = World->SpawnActor<APiece>(archeryClass);
			break;
		// bandit
		case 14:
			generatedPiece = World->SpawnActor<APiece>(rangerClass);
			break;
		case 15:
			generatedPiece = World->SpawnActor<APiece>(assassinClass);
			break;
		case 16:
			generatedPiece = World->SpawnActor<APiece>(thiefClass);
			break;
		case 17:
			generatedPiece = World->SpawnActor<APiece>(beastMasterClass);
			break;
		case 18:
			generatedPiece = World->SpawnActor<APiece>(doggyClass);
			break;
		// foreiger
		case 19:
			generatedPiece = World->SpawnActor<APiece>(mageClass);
			break;
		case 20:
			generatedPiece = World->SpawnActor<APiece>(samuraiClass);
			break;
		case 21:
			generatedPiece = World->SpawnActor<APiece>(cultistClass);
			break;
		case 22:
			generatedPiece = World->SpawnActor<APiece>(cowboyClass);
			break;
		case 24:
			generatedPiece = World->SpawnActor<APiece>(bountyHunterClass);
			break;
		case 25:
			generatedPiece = World->SpawnActor<APiece>(werewolfClass);
			break;
		case 26:
			generatedPiece = World->SpawnActor<APiece>(witchClass);
			break;
		case 27:
			generatedPiece = World->SpawnActor<APiece>(ninjaClass);
			break;
		case 28:
			generatedPiece = World->SpawnActor<APiece>(prisonerClass);
			break;
		default:
			generatedPiece = nullptr;
			break;
		}
	}
	return generatedPiece;
}


APiece* UPieceGenerator::generateEmpirePiece(UWorld* World) {
	APiece* generatedPiece = nullptr;

	if (World) {
		int aRandomNum = FMath::FRandRange(1, totalPiecesNum);
		switch (aRandomNum) {
			// empire
		case 1:
			generatedPiece = World->SpawnActor<APiece>(pawnClass);
			break;
		case 2:
			generatedPiece = World->SpawnActor<APiece>(kingClass);
			break;
		case 3:
			generatedPiece = World->SpawnActor<APiece>(rookClass);
			break;
		case 4:
			generatedPiece = World->SpawnActor<APiece>(knightClass);
			break;
		case 5:
			generatedPiece = World->SpawnActor<APiece>(bishopClass);
			break;
		case 6:
			generatedPiece = World->SpawnActor<APiece>(queenClass);
			break;
		case 7:
			generatedPiece = World->SpawnActor<APiece>(cannonClass);
			break;
		case 8:
			generatedPiece = World->SpawnActor<APiece>(warriorClass);
			break;
		case 9:
			generatedPiece = World->SpawnActor<APiece>(doctorClass);
			break;
		case 10:
			generatedPiece = World->SpawnActor<APiece>(guardClass);
			break;
		case 11:
			generatedPiece = World->SpawnActor<APiece>(catapultClass);
			break;
		case 12:
			generatedPiece = World->SpawnActor<APiece>(priestClass);
			break;
		case 13:
			generatedPiece = World->SpawnActor<APiece>(archeryClass);
			break;
		default:
			generatedPiece = nullptr;
			break;
		}
	}
	return generatedPiece;
}
APiece* UPieceGenerator::generateBanditPiece(UWorld* World) {
	APiece* generatedPiece = nullptr;

	if (World) {
		int aRandomNum = FMath::FRandRange(1, totalPiecesNum);
		switch (aRandomNum) {
			// bandit
		case 1:
			generatedPiece = World->SpawnActor<APiece>(rangerClass);
			break;
		case 2:
			generatedPiece = World->SpawnActor<APiece>(assassinClass);
			break;
		case 3:
			generatedPiece = World->SpawnActor<APiece>(thiefClass);
			break;
		case 4:
			generatedPiece = World->SpawnActor<APiece>(beastMasterClass);
			break;
		case 5:
			generatedPiece = World->SpawnActor<APiece>(doggyClass);
			break;
		default:
			generatedPiece = nullptr;
			break;
		}
	}
	return generatedPiece;
}

APiece* UPieceGenerator::generateForeigerPiece(UWorld* World) {
	APiece* generatedPiece = nullptr;

	if (World) {
		int aRandomNum = FMath::FRandRange(1, totalPiecesNum);
		switch (aRandomNum) {
			// foreiger
		case 1:
			generatedPiece = World->SpawnActor<APiece>(mageClass);
			break;
		case 2:
			generatedPiece = World->SpawnActor<APiece>(samuraiClass);
			break;
		case 3:
			generatedPiece = World->SpawnActor<APiece>(cultistClass);
			break;
		case 4:
			generatedPiece = World->SpawnActor<APiece>(cowboyClass);
			break;
		case 5:
			generatedPiece = World->SpawnActor<APiece>(bountyHunterClass);
			break;
		case 6:
			generatedPiece = World->SpawnActor<APiece>(werewolfClass);
			break;
		case 7:
			generatedPiece = World->SpawnActor<APiece>(witchClass);
			break;
		case 8:
			generatedPiece = World->SpawnActor<APiece>(ninjaClass);
			break;
		case 9:
			generatedPiece = World->SpawnActor<APiece>(prisonerClass);
			break;
		default:
			generatedPiece = nullptr;
			break;
		}
	}
	return generatedPiece;
}