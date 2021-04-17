// Fill out your copyright notice in the Description page of Project Settings.

#include "LightSwitchCodeOnly.h"

#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ALightSwitchCodeOnly::ALightSwitchCodeOnly()
{
    DesiredIntensity = 3000.0f;
	
    PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
    PointLight1->Intensity = DesiredIntensity;
    PointLight1->SetVisibility(true);
    RootComponent = PointLight1;

    Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
    Sphere1->InitSphereRadius(250.0f);
    Sphere1->SetupAttachment(RootComponent);

    Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchCodeOnly::OnOverlapBegin);       // set up a notification for when this component overlaps something
    Sphere1->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchCodeOnly::OnOverlapEnd);       // set up a notification for when this component overlaps something

}

void ALightSwitchCodeOnly::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor && (OtherActor != this) && OtherComp)
    {
        ToggleLight();
    }
}

void ALightSwitchCodeOnly::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && (OtherActor != this) && OtherComp)
    {
        ToggleLight();
    }
}

void ALightSwitchCodeOnly::ToggleLight()
{
    PointLight1->ToggleVisibility();
}

// Called when the game starts or when spawned
void ALightSwitchCodeOnly::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightSwitchCodeOnly::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

