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
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is possessing: %s"), *ControlledTank->GetName()); 
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
		GetControlledTank()->AimAt(HitLocation); /// This can be used as we have included "Tank.h" in the header file
	}
}

// Get world location through a linetrace from crosshair, true if it hits landscape
bool ARealTankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//OutHitLocation = FVector(1.0); // Going to return a vector that gives 1,1,1 because it is a pointer - The variable can change because it is a reference pointer.

	// Find crosshair position in pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY); /// Finds game window size

	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation); 

	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection; /// value is being set by the GetLookDirection method since its using the "FVector& LookDirection"
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// Line-trace through that look direction, and see what we hit (up to a maximum range)
		return GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	
	return true;
}

bool ARealTankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; /// this is to be ignored - though we need to pass it into the DeprojectScreenPositionToWorld() so it needs to be here.

	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	return true;
}

bool ARealTankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility))
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0.0f);
	return false;
}

