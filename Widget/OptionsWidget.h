// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameModeWidget.h"
#include "Engine/Engine.h"
#include "GameFramework/GameUserSettings.h"

#include "OptionsWidget.generated.h"

/**
* Option widget is different to other widgets
* It is outside of gamemode, so it is able to have its own attributes instead of accessing gamemode attribute
*/
UCLASS(Blueprintable)
class UOptionsWidget : public UGameModeWidget {
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		int languageIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		ELanguage currentLanguage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText languageTitleText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText languageOptionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		int windowModeIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		TEnumAsByte<EWindowMode::Type> currentWindowMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText windoeModeTitleText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText windoeModeOptionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		int resolutionIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FIntPoint currentResolution;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText resolutionTitleText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText resolutionOptionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		int graphicsIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText graphicsTitleText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText graphicsOptionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		int VsyncIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		bool currentVsync;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText vsyncTitleText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting")
		FText vsyncOptionText;

	// all text to display
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText languageTitleEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText languageTitleChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText languageTitleSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText languageOptionEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText languageOptionChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText languageOptionSpanish;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeTitleEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeTitleChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeTitleSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionEnglishFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionEnglishWinFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionEnglishWindowed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionChineseFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionChineseWinFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionChineseWindowed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionSpanishFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionSpanishWinFull;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText windowModeOptionSpanishWindowed;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText resolutionTitleEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText resolutionTitleChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText resolutionTitleSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText resolutionOption;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsTitleEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsTitleChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsTitleSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionEnglishLow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionEnglishMedium;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionEnglishHigh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionEnglishEpic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionEnglishUltra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionChineseLow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionChineseMedium;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionChineseHigh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionChineseEpic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionChineseUltra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionSpanishLow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionSpanishMedium;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionSpanishHigh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionSpanishEpic;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText graphicsOptionSpanishUltra;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncTitleEnglish;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncTitleChinese;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncTitleSpanish;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncOptionEnglishYes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncOptionEnglishNo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncOptionChineseYes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncOptionChineseNo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncOptionSpanishYes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Setting Text")
		FText vsyncOptionSpanishNo;

public:
	UOptionsWidget();
	
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void loadLanguage(ELanguage WindowMode);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateLanguageIndex(int modifier);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateLanguageText();


	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void loadWindowMode(TEnumAsByte<EWindowMode::Type> WindowMode);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateWindowModeIndex(int modifier);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateWindowModeText();

	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void loadResolution(FIntPoint pointValue);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateResolutionIndex(int modifier);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateResolutionText();

	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void loadGraphics(int aGraphicValue);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateGraphicsIndex(int modifier);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateGraphicsText();

	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void loadVsync(bool aCurrentVsync);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateVsyncIndex(int modifier);
	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void updateVsyncText();


	UFUNCTION(BlueprintCallable, Category = "Game Setting")
		void applyAllSettings();

};



