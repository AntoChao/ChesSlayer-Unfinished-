// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameModeWidget.h"
#include "../Level/InitGameMode.h"

#include "InitGameModeWidget.generated.h"

UCLASS()
class UInitGameModeWidget : public UGameModeWidget
{
	GENERATED_BODY()

public:
	UInitGameModeWidget();

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		bool isContinueAvailable = false;

	UFUNCTION(BlueprintCallable, Category = "Widget Method")
		void loadAllText();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText continueText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText newGameText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText optionsText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText quitText;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText continueEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText continueChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText continueSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText newGameEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText newGameChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText newGameSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText optionsEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText optionsChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText optionsSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText quitEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText quitChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Info")
		FText quitSpanish;

};



