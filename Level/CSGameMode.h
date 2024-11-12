// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

// General
#include "CSInstance.h"
#include "CSSave.h"

// Widget
#include "../Widget/GameModeWidget.h"

// Power
#include "../Power/Power.h"
#include "../Power/AIPowers/AIPower.h"
#include "../Power/PlayerPower.h"
#include "../Power/Relationship.h"

// Piece
#include "../Power/Piece/Piece.h"

#include "CSGameMode.generated.h"

UCLASS(Blueprintable)
class ACSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACSGameMode();

	virtual void BeginPlay() override;

protected:
	// General 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Game Instance")
		UCSInstance* gameInstance = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Game Instance")
		void goToNextGameMode(EGameMode nextGameMode);

	// Widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI Info")
		TSubclassOf<class UGameModeWidget> gameModeWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI Info")
		class UGameModeWidget* gameModeWidget = nullptr;

public:
	// Common shared info
	UFUNCTION(BlueprintCallable, Category = "GameMode")
		virtual void loadInstanceAttributes();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
		virtual void updateInstance();

	UFUNCTION(BlueprintCallable, Category = "GameMode")
		void loadGameModeWidget();
};



