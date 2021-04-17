// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Zombie.generated.h"

// The States that zombie can be in

UENUM(BlueprintType)
enum class ZombieState : uint8
{
	IDLE	UMETA(DisplayName = "IDLE"),
	ROAM	UMETA(DiaplayName = "ROAM"),
	CHASE	UMETA(DisplayName = "CHASE"),
	ATTACK	UMETA(DisplayName = "ATTACK"),
	DEAD	UMETA(DisplayName = "DEAD")
};

UCLASS()
class FINALBETAGAME_API AZombie : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombie();

	// skeletal mesh of zombie
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* ZombieSkeletalMesh;

	// current state of zombie
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Zombie)
		ZombieState State = ZombieState::IDLE;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Zombie)
		ZombieState PreviousState = State;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly);
	bool bIsSprinting = false;
};
