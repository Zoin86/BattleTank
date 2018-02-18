// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetAIControlledTank();
	auto PlayerTank = GetPlayerTank();


	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possessing Tank !")); /// Make sure that the Tank Pawn is properly parented to Tank c++ files
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController is possessing: %s"), *ControlledTank->GetName()); /// this gets the possed pawn
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController can't find any players."))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController has found player in: %s"), *PlayerTank->GetName())
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO move towards the player

		// Aim at the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// fire if ready
		
	}
}
	

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn()); /// allows us to use methods inside ATank - Also allows us to quickly reference it above
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}


