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

// Called every frame
void ARealTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ARealTankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); /// allows us to use methods inside ATank - Also allows us to quickly reference it above
}

void ARealTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()){ return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has side effect, going to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point'
	}
}

// Get world location through a linetrace from crosshair, true if it hits landscape
bool ARealTankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//OutHitLocation = FVector(1.0); // Going to return a vector that gives 1,1,1 because it is a pointer - The variable can change because it is a reference pointer.

	// Find crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY); // Finds game window size
	
	/// This is a struct - Sets ScreenLocations UI paremeters as to where the UI aiming dot should be.
	// Equation takes the Viewport size and multiplies it with the percentage of where the UI element which returns the value of amount of pixels in the UI element is!
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation); 
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	// "De-project" the screen position of the crosshair to a world direction

	// Line-trace through that look direction, and see what we hit (up to a maximum range)
	return true;
}
