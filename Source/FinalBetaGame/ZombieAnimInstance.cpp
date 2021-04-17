#include "ZombieAnimInstance.h"
#include "Zombie.h"
#include "FinalBetaGameCharacter.h"
#include "Math/Rotator.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

/**
 * Used by the animation blueprint to update the animation properties above
 * and decide what animations to play.
 */
void UZombieAnimInstance::UpdateAnimationProperties()
{
	// Try to get the Pawn being animated and return if a nullptr.
	APawn* ZombiePawn = TryGetPawnOwner();
	if (ZombiePawn == nullptr) return;

	// Try to cast the Pawn to our ZombieCharacter since that's the only
	// thing we want to animate.
	AZombie* ZombieCharacter = Cast<AZombie>(ZombiePawn);
	if (ZombieCharacter == nullptr) return;

	// Set the variables that are dependent on states.
	bIsRoaming = ZombieCharacter->State == ZombieState::ROAM;
	bIsChasing = ZombieCharacter->State == ZombieState::CHASE;
	bIsAttacking = ZombieCharacter->State == ZombieState::ATTACK;
	bIsDying = ZombieCharacter->State == ZombieState::DEAD;
}