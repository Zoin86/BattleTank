// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
/// (meta = (BlueprintSpawnableComponent) lets us use this component in blueprints - meta = (BlueprintSpawnableComponent), hidecategories = ("StringName")) allows one to hide categories in the editor
UCLASS(meta = (BlueprintSpawnableComponent)) 
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = ElevationSetup)
		float MaxDegreesPerSecond = 20.0f;
	UPROPERTY(EditAnywhere, Category = ElevationSetup)
		float MaxElevationDegrees = 35.f;
	UPROPERTY(EditAnywhere, Category = ElevationSetup)
		float MinElevevationDegrees = 0.f;	
	
};
