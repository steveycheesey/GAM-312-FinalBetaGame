// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "ZombieAIController.generated.h"

/**
 * 
 */
UCLASS()
class FINALBETAGAME_API AZombieAIController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:
	FTimerHandle TimerHandle;
	UPROPERTY()
		TArray<AActor*> Waypoints;

	UFUNCTION()
		ATargetPoint* GetRandomWayPoint();

	UFUNCTION()
		void GoToRandomWaypoint();
	
};