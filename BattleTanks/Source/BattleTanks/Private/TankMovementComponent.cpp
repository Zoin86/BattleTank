// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrankToSet)
{
	if (!LeftTrackToSet || !RightTrankToSet)
	{
		return;
	}

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrankToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO Prevent extra speed from pressing extra speed buttons.
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward Throw: %f"), Throw)
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
