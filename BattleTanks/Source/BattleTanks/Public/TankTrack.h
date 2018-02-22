// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TankTrack.generated.h"

/**
 * Tank Track used to set maximum driving force, and apply it to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// Max for per track in newtons
	UPROPERTY(EditAnywhere, Category = Setup)
	float TrackMaxDrivingForce = 40000000.f; // 40ton Tank at 10m/s^2 - also 40 million equals that of 400.000 newtons
};
