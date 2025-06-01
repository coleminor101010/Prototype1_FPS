// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSChar.h"
#include "GameFramework/Controller.h"
// Sets default values
AFPSChar::AFPSChar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPSChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AFPSChar::TurnInput(float AxisValue)
{
    Turn = AxisValue;
    if (Controller)
    {
        AddControllerYawInput(Turn);
    }
}

void AFPSChar::LookUpInput(float AxisValue)
{
    LookUp = AxisValue;
    if (Controller)
    {
        AddControllerPitchInput(LookUp);
    }
}

void AFPSChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind axis events
    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

