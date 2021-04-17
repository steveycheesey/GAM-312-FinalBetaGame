// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FinalBetaGameCharacter.h"
#include "FinalBetaGameGameMode.generated.h"


UENUM()
enum EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};
UCLASS(minimalapi)
class AFinalBetaGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFinalBetaGameGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	AFinalBetaGameCharacter* MyCharacter;

	// return current playing state
	UFUNCTION(BlueprintPure, Category = "Health")
		EGamePlayState GetCurrentState() const;

	// sets a new playing state
	void SetCurrentState(EGamePlayState NewState);

private:
	// keeps track of the current playing state
	EGamePlayState CurrentState;

	// handle any function calls that rely upon changing the playing state of game
	void HandleNewState(EGamePlayState NewState);
};