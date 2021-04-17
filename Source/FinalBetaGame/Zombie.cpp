// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AZombie::AZombie()
{
	// Load the assets needed for the ZombieCharacter.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>ZombieSkeletalMeshAsset(TEXT("SkeletalMesh'/Game/Zombie/parasite_l_starkie'"));

	// Create the ZombieCharacter's skeletal mesh and set it to be the mesh loaded above. 
	ZombieSkeletalMesh = GetMesh();
	ZombieSkeletalMesh->SetSkeletalMesh(ZombieSkeletalMeshAsset.Object);
	ZombieSkeletalMesh->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	ZombieSkeletalMesh->SetupAttachment(RootComponent);
}
