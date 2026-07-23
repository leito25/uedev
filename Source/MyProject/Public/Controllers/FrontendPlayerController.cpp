// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/FrontendPlayerController.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void AFrontendPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	
	TArray<AActor*> FoundCameras; // This is a pointer of an array of cameras
	UGameplayStatics::GetAllActorsOfClassWithTag(this, ACameraActor::StaticClass(), FName("Default"), FoundCameras);
	
	if (!FoundCameras.IsEmpty())
	{
		//
		SetViewTarget(FoundCameras[0]);
		UE_LOG(LogTemp, Warning, TEXT("Found Camera: %s"), *FoundCameras[0]->GetName());
		UE_LOG(LogTemp, Warning, TEXT("OK: %s"), *FoundCameras[0]->GetActorNameOrLabel());
	}
}

void AFrontendPlayerController::MyFunctionBPCallable()
{
	UE_LOG(LogTemp, Warning, TEXT("Mover is moving %d"), 100);
}
