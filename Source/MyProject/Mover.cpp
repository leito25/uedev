// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"

// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	// GetOwner
	//AActor* myActor = GetOwner();
	//auto name = myActor->GetName();
	//UE_LOG(LogTemp, Warning, TEXT("My Name Actor git status%s "), *name);
	//UE_LOG(LogTemp, Warning, TEXT("My Name Actor git status%s "), *myActor->GetActorNameOrLabel());
	
	//StartLocation = myActor->GetActorLocation();
	//UE_LOG(LogTemp, Warning, TEXT("Start Location of this is %s "), *StartLocation.ToString());
	////TODO: Mover the object from startpoint to end point // Just a plan
	
	//Avoiding the pointer
	StartLocation = GetOwner()->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s location is %s"), *GetOwner()->GetActorNameOrLabel(), *StartLocation.ToString());
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	
	//Logging
	//UE_LOG(LogTemp,Warning,TEXT("Mover Tiking... "));
	
	// Moving using the Mover Component
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	CurrentLocation.Z += DeltaTime * 100;
	GetOwner()->SetActorLocation(CurrentLocation);
}

