// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BattleTanks.h"
#include "Public/UObject/Class.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "RealTankPlayerController.generated.h" // Generated files must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ARealTankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	void Tick(float DeltaTime) override;


private:
	ATank * GetControlledTank() const;
};
