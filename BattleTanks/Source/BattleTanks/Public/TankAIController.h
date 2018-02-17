// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "BattleTanks.h"
#include "Public/UObject/Class.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

public:
	virtual void BeginPlay() override; // BeginPlay() has to stay public if we want to keep inheriting from this class


private:
	
	ATank* GetAIControlledTank() const; // remember getters can be constants as they dont need to change anything

	ATank* GetPlayerTank() const; 


	
	
};
