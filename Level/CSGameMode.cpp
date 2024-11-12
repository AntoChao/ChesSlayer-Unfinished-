// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSGameMode.h"
#include "../Power/Controller/CSPlayerController.h"
#include "../Power/PlayerPower.h"
#include "UObject/ConstructorHelpers.h"

ACSGameMode::ACSGameMode() {
	// use our custom PlayerController class
	PlayerControllerClass = APlayerController::StaticClass();
}

void ACSGameMode::BeginPlay() {
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("----------------------------------------------"));
	
	loadInstanceAttributes();
	loadGameModeWidget();
}

void ACSGameMode::goToNextGameMode(EGameMode nextGameMode) {
	if (gameInstance) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("goToNextLevel"));
		gameInstance->loadGameModeAttributesDirect(this);
		gameInstance->openNextLevel(nextGameMode);
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("try to goToNextLevel, but instance is invalid"));
	}
}

// virtual function that load necessaries attributes based on dif gamemode
void ACSGameMode::loadInstanceAttributes() {
	gameInstance = Cast<UCSInstance>(UGameplayStatics::GetGameInstance(this));
	if (gameInstance) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("game intance is VALID"));;
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("game intance is NOT VALID"));
	}
}

// virtual function that update attributes based on dif gamemode
void ACSGameMode::updateInstance() {
}

void ACSGameMode::loadGameModeWidget() {
	// attach gamemode widget to player control
	if (IsValid(gameModeWidgetClass)) {
		ACSPlayerController* controller = Cast<ACSPlayerController>(GetWorld()->GetFirstPlayerController());
		gameModeWidget = CreateWidget<UGameModeWidget>(controller, gameModeWidgetClass);
		if (gameModeWidget) {
			gameModeWidget->AddToViewport();
		}
	}
}