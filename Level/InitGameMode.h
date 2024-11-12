// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CSGameMode.h"

#include "InitGameMode.generated.h"

UCLASS(Blueprintable)
class AInitGameMode : public ACSGameMode
{
	GENERATED_BODY()

public:
	AInitGameMode();

	virtual void BeginPlay() override;

protected:
	virtual void loadInstanceAttributes() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		bool isFirstTimeOpening = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Common Values")
		bool isLastGameFinished;

public:
	UFUNCTION(BlueprintCallable, Category = "Level Control")
		bool getIfIsFirstTimeOpening();
	UFUNCTION(BlueprintCallable, Category = "Level Control")
		bool getIfIsLastGameFinished();

};



