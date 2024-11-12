// Copyright Epic Games, Inc. All Rights Reserved.

#include "InitGameModeWidget.h"
#include "Math/IntPoint.h"

UInitGameModeWidget::UInitGameModeWidget() {

}

void UInitGameModeWidget::NativeConstruct() {
    Super::NativeConstruct();
}

void UInitGameModeWidget::loadAllText() {
    UCSInstance* gameInstance = Cast<UCSInstance>(UGameplayStatics::GetGameInstance(this));

    if (gameInstance) {
        switch (gameInstance->getGameLanguage()) {
        case ELanguage::EEnglish:
            continueText = continueEnglish;
            newGameText = newGameEnglish;
            optionsText = optionsEnglish;
            quitText = quitEnglish;
            break;
        case ELanguage::EChinese:
            continueText = continueChinese;
            newGameText = newGameChinese;
            optionsText = optionsChinese;
            quitText = quitChinese;
            break;
        case ELanguage::ESpanish:
            continueText = continueSpanish;
            newGameText = newGameSpanish;
            optionsText = optionsSpanish;
            quitText = quitSpanish;
            break;
        default:
            continueText = continueEnglish;
            newGameText = newGameEnglish;
            optionsText = optionsEnglish;
            quitText = quitEnglish;
            break;
        }
    }
}
