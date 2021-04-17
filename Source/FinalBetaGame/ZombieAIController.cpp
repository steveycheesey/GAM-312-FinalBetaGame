// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void AZombieAIController::BeginPlay()
{
	// call Super or character will never move!!
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(this, ATargetPoint::StaticClass(), Waypoints);

	GoToRandomWaypoint();
}

ATargetPoint* AZombieAIController::GetRandomWayPoint()
{
	// index to get random waypoints for AI to use
	auto index = FMath::RandRange(0, Waypoints.Num() - 1);

	// cast return value to ensure correct type
	return Cast<ATargetPoint>(Waypoints[index]);
}

void AZombieAIController::GoToRandomWaypoint()
{
	MoveToActor(GetRandomWayPoint());
}

void AZombieAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AZombieAIController::GoToRandomWaypoint, 1.0f, false);
}

