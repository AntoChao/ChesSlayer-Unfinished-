// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CSCommonType.generated.h"

// Language enum
UENUM(BlueprintType, Blueprintable)
enum class ELanguage: uint8
{
	EEnglish,
	EChinese,
	ESpanish
};


// Level enum
UENUM(BlueprintType, Blueprintable)
enum class EGameMode : uint8
{
	EInitGameMode,
	EStartGameMode,
	EGameplayGameMode,
	EPostgameGameMode
};

// Power Name enum
UENUM(BlueprintType, Blueprintable)
enum class EPowerName : uint8
{
	EPlayer,
	EEmpire,
	EBandit,
	EForeiger,
	EObstacle
};

// Power Relationship enum
UENUM(BlueprintType, Blueprintable)
enum class ERelationship : uint8
{
	EAlly,
	ENeutro,
	EEnemy
};

// Mission Objective enum
UENUM(BlueprintType, Blueprintable)
enum class EObjective : uint8
{
	EDefeat, /*kill all*/
	EDefense, /*protect an ally piece*/
	ESurvival, /*dont die in x turn*/
	EAssassination, /*kill a specific enemy*/
	EEscort, /*escort an allied piece to a specific place*/
	ECapture, /*capture an enemy piece and bring to a specific place*/
	ERescue /*rescue an allied piece behind enemy lines*/
};

// Square Terrain enum
UENUM(BlueprintType, Blueprintable)
enum class ETerrain : uint8
{
	ELand,
	EOcean,
	EMountain,
	EVoid
};

// maxtrix position
USTRUCT(BlueprintType)
struct FLocation
{
	GENERATED_BODY()

public:
	// Default constructor
	FLocation()
		: x(0), y(0)
	{}

	// Parameterized constructor
	FLocation(float InX, float InY)
		: x(InX), y(InY)
	{}

	// X coordinate
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location")
		float x;

	// Y coordinate
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Location")
		float y;

	bool isEqual(const FLocation& anotherLocation) const {
		return this->x == anotherLocation.x && this->y == anotherLocation.y;
	}

	FLocation add(const FLocation& anotherLocation) const {
		return FLocation(this->x + anotherLocation.x, this->y + anotherLocation.y);
	}

	FLocation subtract(const FLocation& anotherLocation) const {
		return FLocation(this->x - anotherLocation.x, this->y - anotherLocation.y);
	}
};

// class CSMission; 
class UCSMission;
USTRUCT(BlueprintType)
struct FPath
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path Mission")
		UCSMission* FromMission;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Path Mission")
		UCSMission* ToMission;

	FPath() : FromMission(nullptr), ToMission(nullptr) {}

	FPath(UCSMission* InFrom, UCSMission* InTo)
		: FromMission(InFrom), ToMission(InTo) {}
};


// Square Terrain enum
UENUM(BlueprintType, Blueprintable)
enum class EAbilitySelected : uint8
{
	ENone,
	EDefault,
	EOne,
	ETwo
};

// Ability type
UENUM(BlueprintType, Blueprintable)
enum class EAbilityType : uint8
{
	EPassive,
	EMove,
	EBuff,
	EControl
};

// Ability type
UENUM(BlueprintType, Blueprintable)
enum class EAbilityDirection : uint8
{
	ENone,
	EUp,
	EDown,
	ELeft,
	ERight,
	EUpLeft,
	EUpRight,
	EDownLeft,
	EDownRight
};

// All abilities name
UENUM(BlueprintType, Blueprintable)
enum class EAbilityName : uint8
{
	ENone,
	EAxisCharge,
	EAxisMove,
	EBackstab,
	EBlackhole,
	EBroomFlight,
	EDiagonalCharge,
	EHelpingHand,
	EHunt,
	ELaunchStone,
	ELeapingHunt,
	ELJump,
	ELongShot,
	EMarch,
	EMovingShot,
	EOmniCharge,
	EOmniMove,
	EPetStep,
	EPortal,
	EQuickDraw,
	EQuickSlash,
	ERush,
	EShadowStep,
	ESheldPush,
	ESlashAndShoot,
	ESpearVault,
	ESwiftStep
};