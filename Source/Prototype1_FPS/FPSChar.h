// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FPSChar.generated.h"

UCLASS()
class PROTOTYPE1_FPS_API AFPSChar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFPSChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	
public:
	// Variables to store input values
	float Turn;
	float LookUp;

	// Input functions
	void TurnInput(float AxisValue);
	void LookUpInput(float AxisValue);


};
