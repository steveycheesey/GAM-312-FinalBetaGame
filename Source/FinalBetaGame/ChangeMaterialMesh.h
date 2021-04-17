// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChangeMaterialMesh.generated.h"

UCLASS()
class FINALBETAGAME_API AChangeMaterialMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChangeMaterialMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
		class UMaterial* OnMaterial;

	UPROPERTY(EditAnywhere)
		class UMaterial* OffMaterial;

	UPROPERTY()
		class UBoxComponent* MyBoxComponent;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
