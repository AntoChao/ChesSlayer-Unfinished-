// Copyright Epic Games, Inc. All Rights Reserved.

#include "OptionsWidget.h"


UOptionsWidget::UOptionsWidget() {

}

void UOptionsWidget::NativeConstruct() {
    Super::NativeConstruct();
}
/*
void UOptionsWidget::loadAttributesValue() {
    
    // initialize the game instance
    UCSInstance* gameInstance = Cast<UCSInstance>(UGameplayStatics::GetGameInstance(this));

    if (gameInstance) {
        currentLanguage = gameInstance->getGameLanguage();
        loadLanguage(currentLanguage);
    }

    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (UserSettings) {
        loadWindowMode(UserSettings->GetFullscreenMode());
        loadResolution(UserSettings->GetScreenResolution());
        loadGraphics(UserSettings->GetOverallScalabilityLevel());
        loadVsync(UserSettings->IsVSyncEnabled());
    }
}*/


void UOptionsWidget::loadLanguage(ELanguage aLanguage) {
    switch (aLanguage) {
    case ELanguage::EEnglish:
        languageIndex = 0;
        break;
    case ELanguage::EChinese:
        languageIndex = 1;
        break;
    case ELanguage::ESpanish:
        languageIndex = 2;
        break;
    default:
        languageIndex = 0;
        break;
    }
    currentLanguage = aLanguage;
    updateLanguageText();
    
}
void UOptionsWidget::updateLanguageIndex(int modifier) {
    languageIndex = FMath::Clamp(languageIndex + modifier, 0, 2);
    
    switch (languageIndex){
    case 0:
        currentLanguage = ELanguage::EEnglish;
        break;
    case 1:
        currentLanguage = ELanguage::EChinese;
        break;
    case 2:
        currentLanguage = ELanguage::ESpanish;
        break;
    default:
        currentLanguage = ELanguage::EEnglish;
        break;
    }
    
    updateLanguageText();

    // update language in instance
    UCSInstance* gameInstance = Cast<UCSInstance>(UGameplayStatics::GetGameInstance(this));

    if (gameInstance) {
        gameInstance->setGameLanguage(currentLanguage);
    }
}
void UOptionsWidget::updateLanguageText() {
    switch (currentLanguage) {
    case ELanguage::EEnglish:
        languageTitleText = languageTitleEnglish;
        languageOptionText = languageOptionEnglish;
        break;
    case ELanguage::EChinese:
        languageTitleText = languageTitleChinese;
        languageOptionText = languageOptionChinese;
        break;
    case ELanguage::ESpanish:
        languageTitleText = languageTitleSpanish;
        languageOptionText = languageOptionSpanish;
        break;
    default:
        languageTitleText = languageTitleEnglish;
        languageOptionText = languageOptionEnglish;
        break;
    }
}


void UOptionsWidget::loadWindowMode(TEnumAsByte<EWindowMode::Type> WindowMode) {
    // Get the current window mode
    switch (WindowMode) {
    case EWindowMode::Fullscreen:
        windowModeIndex = 0;
        break;
    case EWindowMode::WindowedFullscreen:
        windowModeIndex = 1;
        break;
    case EWindowMode::Windowed:
        windowModeIndex = 2;
        break;
    default:
        windowModeIndex = 0;
        break;
    }
    currentWindowMode = WindowMode;
    updateWindowModeText();
}
void UOptionsWidget::updateWindowModeIndex(int modifier) {
    windowModeIndex = FMath::Clamp(windowModeIndex + modifier, 0, 2);
    switch (windowModeIndex) {
    case 0:
        currentWindowMode = EWindowMode::Fullscreen;
        break;
    case 1:
        currentWindowMode = EWindowMode::WindowedFullscreen;
        break;
    case 2:
        currentWindowMode = EWindowMode::Windowed;
        break;
    default:
        currentWindowMode = EWindowMode::Fullscreen;
        break;
    }
    updateWindowModeText();
}
void UOptionsWidget::updateWindowModeText() {
    switch (currentLanguage) {
    case ELanguage::EEnglish:
        windoeModeTitleText = windowModeTitleEnglish;
        switch (currentWindowMode) {
        case EWindowMode::Fullscreen:
            windoeModeOptionText = windowModeOptionEnglishFull;
            break;
        case EWindowMode::WindowedFullscreen:
            windoeModeOptionText = windowModeOptionEnglishWinFull;
            break;
        case EWindowMode::Windowed:
            windoeModeOptionText = windowModeOptionEnglishWindowed;
            break;
        default:
            windoeModeOptionText = windowModeOptionEnglishFull;
            break;
        }
        break;

    case ELanguage::EChinese:
        windoeModeTitleText = windowModeTitleChinese;
        switch (currentWindowMode) {
        case EWindowMode::Fullscreen:
            windoeModeOptionText = windowModeOptionChineseFull;
            break;
        case EWindowMode::WindowedFullscreen:
            windoeModeOptionText = windowModeOptionChineseWinFull;
            break;
        case EWindowMode::Windowed:
            windoeModeOptionText = windowModeOptionChineseWindowed;
            break;
        default:
            windoeModeOptionText = windowModeOptionEnglishFull;
            break;
        }
        break;

    case ELanguage::ESpanish:
        windoeModeTitleText = windowModeTitleSpanish;
        switch (currentWindowMode) {
        case EWindowMode::Fullscreen:
            windoeModeOptionText = windowModeOptionSpanishFull;
            break;
        case EWindowMode::WindowedFullscreen:
            windoeModeOptionText = windowModeOptionSpanishWinFull;
            break;
        case EWindowMode::Windowed:
            windoeModeOptionText = windowModeOptionSpanishWindowed;
            break;
        default:
            windoeModeOptionText = windowModeOptionEnglishFull;
            break;
        }
        break;

    default:
        windoeModeTitleText = windowModeTitleEnglish;
        switch (currentWindowMode) {
        case EWindowMode::Fullscreen:
            windoeModeOptionText = windowModeOptionEnglishFull;
            break;
        case EWindowMode::WindowedFullscreen:
            windoeModeOptionText = windowModeOptionEnglishWinFull;
            break;
        case EWindowMode::Windowed:
            windoeModeOptionText = windowModeOptionEnglishWindowed;
            break;
        default:
            windoeModeOptionText = windowModeOptionEnglishFull;
            break;
        }
        break;
    }
}


void UOptionsWidget::loadResolution(FIntPoint resolutionValue) {
    if (resolutionValue == FIntPoint(640, 480)) {
        resolutionIndex = 0;
    }
    else if (resolutionValue == FIntPoint(1280, 1024)) {
        resolutionIndex = 1;
    }
    else if (resolutionValue == FIntPoint(1920, 1080)) {
        resolutionIndex = 2;
    }
    else if (resolutionValue == FIntPoint(2560, 1440)) {
        resolutionIndex = 3;
    }
    currentResolution = resolutionValue;
    updateResolutionText();
}
void UOptionsWidget::updateResolutionIndex(int modifier) {
    resolutionIndex = FMath::Clamp(resolutionIndex + modifier, 0, 3);
    
    switch (resolutionIndex) {
    case 0:
        currentResolution = FIntPoint(640, 480);
        break;
    case 1:
        currentResolution = FIntPoint(1280, 1024);
        break;
    case 2:
        currentResolution = FIntPoint(1920, 1080);
        break;
    case 3:
        currentResolution = FIntPoint(2560, 1440);
        break;
    default:
        currentResolution = FIntPoint(1920, 1080);
        break;
    }

    updateResolutionText();
}
void UOptionsWidget::updateResolutionText() {
    switch (currentLanguage) {
    
    case ELanguage::EEnglish:
        resolutionTitleText = resolutionTitleEnglish;
        break;
    case ELanguage::EChinese:
        resolutionTitleText = resolutionTitleChinese;
        break;
    case ELanguage::ESpanish:
        resolutionTitleText = resolutionTitleSpanish;
        break;
    default:
        resolutionTitleText = resolutionTitleEnglish;        
        break;
    }

    resolutionOption = FText::Format(FText::FromString(TEXT("{0}X{1}")),
                        FText::AsNumber(currentResolution.X),
                        FText::AsNumber(currentResolution.Y));
}


void UOptionsWidget::loadGraphics(int aGraphicValue) {
    graphicsIndex = aGraphicValue;
    updateGraphicsText();
}
void UOptionsWidget::updateGraphicsIndex(int modifier) {
    graphicsIndex = FMath::Clamp(graphicsIndex + modifier, 0, 4);
    updateGraphicsText();
}
void UOptionsWidget::updateGraphicsText() {
    switch (currentLanguage) {
    case ELanguage::EEnglish:
        graphicsTitleText = graphicsTitleEnglish;
        switch (graphicsIndex) {
        case 0:
            graphicsOptionText = graphicsOptionEnglishLow;
            break;
        case 1:
            graphicsOptionText = graphicsOptionEnglishMedium;
            break;
        case 2:
            graphicsOptionText = graphicsOptionEnglishHigh;
            break;
        case 3:
            graphicsOptionText = graphicsOptionEnglishEpic;
            break;
        case 4:
            graphicsOptionText = graphicsOptionEnglishUltra;
            break;
        default:
            graphicsOptionText = graphicsOptionEnglishLow;
            break;
        }
        break;

    case ELanguage::EChinese:
        graphicsTitleText = graphicsTitleChinese;
        switch (graphicsIndex) {
        case 0:
            graphicsOptionText = graphicsOptionChineseLow;
            break;
        case 1:
            graphicsOptionText = graphicsOptionChineseMedium;
            break;
        case 2:
            graphicsOptionText = graphicsOptionChineseHigh;
            break;
        case 3:
            graphicsOptionText = graphicsOptionChineseEpic;
            break;
        case 4:
            graphicsOptionText = graphicsOptionChineseUltra;
            break;
        default:
            graphicsOptionText = graphicsOptionChineseLow;
            break;
        }
        break;

    case ELanguage::ESpanish:
        graphicsTitleText = graphicsTitleSpanish;
        switch (graphicsIndex) {
        case 0:
            graphicsOptionText = graphicsOptionSpanishLow;
            break;
        case 1:
            graphicsOptionText = graphicsOptionSpanishMedium;
            break;
        case 2:
            graphicsOptionText = graphicsOptionSpanishHigh;
            break;
        case 3:
            graphicsOptionText = graphicsOptionSpanishEpic;
            break;
        case 4:
            graphicsOptionText = graphicsOptionSpanishUltra;
            break;
        default:
            graphicsOptionText = graphicsOptionSpanishLow;
            break;
        }
        break;

    default:
        graphicsTitleText = windowModeTitleEnglish;
        switch (graphicsIndex) {
        case 0:
            graphicsOptionText = graphicsOptionEnglishLow;
            break;
        case 1:
            graphicsOptionText = graphicsOptionEnglishMedium;
            break;
        case 2:
            graphicsOptionText = graphicsOptionEnglishHigh;
            break;
        case 3:
            graphicsOptionText = graphicsOptionEnglishEpic;
            break;
        case 4:
            graphicsOptionText = graphicsOptionEnglishUltra;
            break;
        default:
            graphicsOptionText = graphicsOptionEnglishLow;
            break;
        }
        break;
    }
}


void UOptionsWidget::loadVsync(bool aCurrentVsync) {
    if (aCurrentVsync) {
        VsyncIndex = 0;
        aCurrentVsync = false;
    }
    else {
        VsyncIndex = 1;
        aCurrentVsync = true;
    }
    updateVsyncText();
}
void UOptionsWidget::updateVsyncIndex(int modifier) {
    VsyncIndex = FMath::Clamp(VsyncIndex + modifier, 0, 1);
    if (VsyncIndex == 0) {
        currentVsync = false;
    }
    else {
        currentVsync = true;
    }
    updateVsyncText();
}
void UOptionsWidget::updateVsyncText() {
    switch (currentLanguage) {

    case ELanguage::EEnglish:
        vsyncTitleText = vsyncTitleEnglish;
        if (currentVsync) {
            vsyncOptionText = vsyncOptionEnglishYes;
        }
        else {
            vsyncOptionText = vsyncOptionEnglishNo;
        }
        break;
    case ELanguage::EChinese:
        vsyncTitleText = vsyncTitleChinese;
        if (currentVsync) {
            vsyncOptionText = vsyncOptionChineseYes;
        }
        else {
            vsyncOptionText = vsyncOptionChineseNo;
        }
        break;
    case ELanguage::ESpanish:
        vsyncTitleText = vsyncTitleSpanish;
        if (currentVsync) {
            vsyncOptionText = vsyncOptionSpanishYes;
        }
        else {
            vsyncOptionText = vsyncOptionSpanishNo;
        }
        break;
    default:
        vsyncTitleText = vsyncTitleEnglish;
        if (currentVsync) {
            vsyncOptionText = vsyncOptionEnglishYes;
        }
        else {
            vsyncOptionText = vsyncOptionEnglishNo;
        }
        break;
    }
}


void UOptionsWidget::applyAllSettings() {
    // initialize the game instance
    UCSInstance* gameInstance = Cast<UCSInstance>(UGameplayStatics::GetGameInstance(this));

    if (gameInstance) {
        gameInstance->setGameLanguage(currentLanguage);
    }

    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (UserSettings){
        // Set fullscreen/windowed mode
        UserSettings->SetFullscreenMode(currentWindowMode);

        // Set resolution
        UserSettings->SetScreenResolution(currentResolution);

        // Set graphics quality
        UserSettings->SetOverallScalabilityLevel(graphicsIndex);
        
        // Set V-Sync
        UserSettings->SetVSyncEnabled(currentVsync);

        // Apply changes and save to config file
        UserSettings->ApplySettings(true);  // true means save settings to config file
    }
}