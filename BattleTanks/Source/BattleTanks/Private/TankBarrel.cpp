// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Elevate with speed: %f"), DegreesPerSecond)
	// Move Barrel the right amount this frame
	// Given a max elevation speed and a frame target
}