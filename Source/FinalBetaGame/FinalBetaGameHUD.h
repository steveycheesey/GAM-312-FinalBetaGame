// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FinalBetaGameHUD.generated.h"

UCLASS()
class AFinalBetaGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFinalBetaGameHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	// override beginplay function
	virtual void BeginPlay() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UPROPERTY(EditAnywhere, Category = "Health")
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	// create object of new uuserwidget class
	UPROPERTY(EditAnywhere, Category = "Health")
		class UUserWidget* CurrentWidget;
};

