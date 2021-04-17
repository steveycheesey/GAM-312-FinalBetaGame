// Copyright Epic Games, Inc. All Rights Reserved.

#include "FinalBetaGameGameMode.h"
#include "FinalBetaGameHUD.h"
#include "Kismet/GameplayStatics.h"
#include "FinalBetaGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFinalBetaGameGameMode::AFinalBetaGameGameMode()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFinalBetaGameHUD::StaticClass();
}

void AFinalBetaGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AFinalBetaGameCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AFinalBetaGameGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState AFinalBetaGameGameMode::GetCurrentState() const
{
	return CurrentState;
}

void AFinalBetaGameGameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AFinalBetaGameGameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::EPlaying:
	{
		// do nothing
	}
	break;
	// Unknown/default state
	case EGamePlayState::EGameOver:
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	break;
	// Unknown/default state
	default:
	case EGamePlayState::EUnknown:
	{
		// do nothing
	}
	break;
	}
}