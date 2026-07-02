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
	UE_LOG(LogTemp, Display, TEXT("MovingPlatform BeginPlay 1"));
	UE_LOG(LogTemp, Display, TEXT("MovingPlatform BeginPlay 2"));
	UE_LOG(LogTemp, Display, TEXT("MovingPlatform BeginPlay 3"));
	
	int myInt;
	myInt = 1;
	UE_LOG(LogTemp, Display, TEXT("MovingPlatform BeginPlay Int = %d"), myInt);
	bool is_DoneBool = false;
	is_DoneBool = true;
	UE_LOG(LogTemp, Display, TEXT("MovingPlatform BeginPlay isDoneBool = %s"), is_DoneBool ? TEXT("myTrue") : TEXT("myFalse"));
	
	FString myString = FString("Hello World");
	UE_LOG(LogTemp, Display, TEXT("myString = %s"), *myString);
	
	// Game Progeamming data
	
	NumberOfApples = 10;
	
	NumberOfOranges = 7;
	float Probability = 0.35f;
	
	
	UE_LOG(LogTemp, Display, TEXT("Number of Apples = %d and the NumberOfOranges = %d"), NumberOfApples, NumberOfOranges);
	UE_LOG(LogTemp, Display, TEXT("The probability to find an apple is = %.2f"), Probability);
	
	//myLocation.X = -440.0f;
	//myLocation.Y = -950.0f;
	//myLocation.Z = 810.0f;
	
	//init
	//(X=0.105691,Y=0.268293,Z=0.000000)
	//(X=-450.000000,Y=-950.000000,Z=30.000000)
	//startPoint = FVector(-450.0f, -950.0f, 0.0f);
	//end
	// -440.0f / -950.0f / 810.0f
	//endPoint = FVector(-450.0f, -950.0f, 810.0f);

	//UE_LOG(LogTemp, Warning, TEXT("Mi Vector: %s"), *myLocation.ToString());
	
	SetActorLocation(startPoint);
	myLocation = startPoint;
	bool isUp = false;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	
	//totalFruits = NumberOfApples + NumberOfOranges;
	//UE_LOG(LogTemp, Display, TEXT("1 - The total of fruits are = %d"), NumberOfApples + NumberOfOranges);
	//UE_LOG(LogTemp, Display, TEXT("2 - The total of fruits are = %d"), totalFruits);
	//myLocation.Z = myLocation.Z - 1.0f;
	//SetActorLocation(myLocation);
	//UE_LOG(LogTemp, Warning, TEXT("Mi Vector Before: %s"), *myLocation.ToString());
	//auto v = GetActorLocation().Z;
	//UE_LOG(LogTemp, Warning, TEXT("Mi Vector v: %f"), v);
	//UE_LOG(LogTemp, Warning, TEXT("Mi Vector startPoint.Z: %f"), startPoint.Z)
	

	/*if (GetActorLocation().Z < endPoint.Z and isUp == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Same: "));
		myLocation.Z = myLocation.Z + 1.0f;
		SetActorLocation(myLocation);
		isUp = true;
		if (GetActorLocation().Z > endPoint.Z and isUp == true)
		{
			myLocation.Z = myLocation.Z - 1.0f;
			SetActorLocation(myLocation);
			
			//UE_LOG(LogTemp, Warning, TEXT("End Point: %s"), *myLocation.ToString());
		}
	}*/
	
	// Approach by using a Sin function, more easy
	// Get running time
	//float Time = GetWorld()->GetTimeSeconds();

	// Calculate a smooth -1.0 to 1.0 wave, multiply by your movement range, and add to start height
	//float NewZ = startPoint.Z + (FMath::Sin(Time * SpeedMultiplier) * TravelDistance);

	//SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, NewZ));
	//
	// 1. Get your current position
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();

	if (isUp)
	{
		// Move up toward the end point
		//CurrentLocation.Z += 100.0f * DeltaTime;
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);

		// Check if we reached or passed the highest point
		if (CurrentLocation.Z >= endPoint.Z)
		{
			isUp = false; // Switch direction to go down next frame
		}
	}
	else
	{
		// Move down toward the start point
		//CurrentLocation.Z -= 10.0f * DeltaTime;
		
		CurrentLocation = CurrentLocation - (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);

		// Check if we reached or passed the lowest point (startPoint)
		if (CurrentLocation.Z <= startPoint.Z)
		{
			isUp = true; // Switch direction to go up next frame
			UE_LOG(LogTemp, Warning, TEXT("End Point: %s"), *myLocation.ToString());
		}
	}
}

