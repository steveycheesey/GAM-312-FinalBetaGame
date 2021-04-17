#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ZombieAnimInstance.generated.h"

/**
 * Manages the booleans needed by the animation blueprint to decide what
 * animation needs to be run.
 */
UCLASS()
class FINALBETAGAME_API UZombieAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	// Is Zombie roaming or not.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bIsRoaming;

	// Is Zombie chasing or not.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bIsChasing;

	// Is Zombie attacking or not.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bIsAttacking;

	// Is Zombie dying or not.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bIsDying;

	// Used by the animation blueprint to update the animation properties above
	// and decide what animations to play.
	UFUNCTION(BlueprintCallable, Category = "UpdateAnimationProperties")
		void UpdateAnimationProperties();
};