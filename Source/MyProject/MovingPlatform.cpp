// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

#include <string>

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	FString MyName = GetName();

	// Call get Actor Location
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);	
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	//Calculate distance
	DistanceMoved = GetDistanceMoved();
	
	// Go back condition
	if (DistanceMoved >= MoveDistance)
	{
		//Overshoot
		float Overshoot = DistanceMoved - MoveDistance;
		FString PlatformName = GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s Overshoot by %f"), *PlatformName, Overshoot);
		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector NewStartLocation = StartLocation + (MoveDirection * MoveDistance);
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;
		
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	// Rotate the platform
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

