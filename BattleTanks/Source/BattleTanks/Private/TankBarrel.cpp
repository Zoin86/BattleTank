// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move Barrel the right amount this frame
	// Given a max elevation speed and a frame target

	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Time: %f - Elevate with speed: %f"), Time, RelativeSpeed)
}