// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* barrelToSet){
	TankAimingComponent->SetBarrelReference(barrelToSet);
}

void ATank::SetTurretReference(UTankTurret* turretToSet){
	TankAimingComponent->SetTurretReference(turretToSet);
}

void ATank::Fire(){	
	auto Time = GetWorld()->GetTimeSeconds(); // for check if anything is running
	UE_LOG(LogTemp, Warning, TEXT(" %f: Tank Fire"), Time);
}


void ATank::AimAt(FVector hitLocation){
	auto tankName = this->GetName();
	TankAimingComponent->AimAt(hitLocation,lauchSpeed,tankName);
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

