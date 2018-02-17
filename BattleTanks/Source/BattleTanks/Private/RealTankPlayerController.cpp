// Fill out your copyright notice in the Description page of Project Settings.

#include "RealTankPlayerController.h"


void ARealTankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing Tank !"), *GetName()); /// Make sure that the Tank Pawn is properly parented to Tank c++ files
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possessing: %s"), *ControlledTank->GetName()); /// this gets the possed pawn
		return;
	}
}

ATank* ARealTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); /// allows us to use methods inside ATank - Also allows us to quickly reference it above
}