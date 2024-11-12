// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameModeWidget.h"

#include "StartGameModeWidget.generated.h"

UCLASS(Blueprintable)
class UStartGameModeWidget : public UGameModeWidget
{
	GENERATED_BODY()

public:
	UStartGameModeWidget();

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultyText;

	UFUNCTION(BlueprintCallable, Category = "Widget Method")
		void updateDifficultyText(int aDifficulty);


	// all text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultyEnglishNormal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultyEnglishHard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultyEnglishExpert;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultyChineseNormal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultyChineseHard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultyChineseExpert;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultySpanishNormal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultySpanishHard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText difficultySpanishExpert;
};



