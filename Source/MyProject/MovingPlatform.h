// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class MYPROJECT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void MovePlatform(float DeltaTime);
	
	UPROPERTY(EditAnywhere)
	int NumberOfApples = 0;
	
	UPROPERTY(EditAnywhere)
	int NumberOfOranges = 0;
	
	UPROPERTY(VisibleAnywhere)
	int totalFruits = 0;
	
	UPROPERTY(EditAnywhere)
	FVector PlatformVelocity = FVector(0.0f, 0.0f, 0.0f);

	
	UPROPERTY(EditAnywhere)
	FVector myLocation = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere)
	FVector startPoint = FVector(0.0f, 0.0f, 0.0f);
	UPROPERTY(EditAnywhere)
	FVector endPoint = FVector(0.0f, 0.0f, 0.0f);
	
	UPROPERTY(EditAnywhere)
	bool isUp = false;
};