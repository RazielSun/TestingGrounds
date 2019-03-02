// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TestingGroundsHUD.generated.h"

UCLASS()
class ATestingGroundsHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATestingGroundsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	/** If true, show crosshair. */
	UPROPERTY(BlueprintReadWrite, Category = HUD)
	uint8 bShowCrosshair : 1;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

