// Copyright Epic Games, Inc. All Rights Reserved.

#include "StartGameModeWidget.h"

UStartGameModeWidget::UStartGameModeWidget() {

}

void UStartGameModeWidget::NativeConstruct() {
    Super::NativeConstruct();
}

void UStartGameModeWidget::updateDifficultyText(int aDifficulty) {
    UCSInstance* gameInstance = Cast<UCSInstance>(UGameplayStatics::GetGameInstance(this));
    if (gameInstance) {
        ELanguage currentLangauge = gameInstance->getGameLanguage();

        switch (currentLangauge) {
        case ELanguage::EEnglish:
            switch (aDifficulty) {
            case 0:
                difficultyText = difficultyEnglishNormal;
                break;
            case 1:
                difficultyText = difficultyEnglishHard;
                break;
            case 2:
                difficultyText = difficultyEnglishExpert;
                break;
            default:
                difficultyText = difficultyEnglishNormal;
                break;
            }
            break;
        case ELanguage::EChinese:
            switch (aDifficulty) {
            case 0:
                difficultyText = difficultyChineseNormal;
                break;
            case 1:
                difficultyText = difficultyChineseHard;
                break;
            case 2:
                difficultyText = difficultyChineseExpert;
                break;
            default:
                difficultyText = difficultyEnglishNormal;
                break;
            }
            break;
        case ELanguage::ESpanish:
            switch (aDifficulty) {
            case 0:
                difficultyText = difficultySpanishNormal;
                break;
            case 1:
                difficultyText = difficultySpanishHard;
                break;
            case 2:
                difficultyText = difficultySpanishExpert;
                break;
            default:
                difficultyText = difficultyEnglishNormal;
                break;
            }
            break;
        default:
            switch (aDifficulty) {
            case 0:
                difficultyText = difficultyEnglishNormal;
                break;
            case 1:
                difficultyText = difficultyEnglishHard;
                break;
            case 2:
                difficultyText = difficultyEnglishExpert;
                break;
            default:
                difficultyText = difficultyEnglishNormal;
                break;
            }
            break;
        }
    }
}