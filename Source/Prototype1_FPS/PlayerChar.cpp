

#include "PlayerChar.h"


APlayerChar::APlayerChar()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}

void APlayerChar::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerChar::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find forward direction
		const FRotator Rotation{ Controller->GetControlRotation()};
		const FRotator YawRotation{ 0, Rotation.Yaw, 0 };

		const FVector Direction{ FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::X) };
		AddMovementInput(Direction, Value);
	}
}

void APlayerChar::MoveRight(float Value)
{
	// find right direction
	const FRotator Rotation{ Controller->GetControlRotation() };
	const FRotator YawRotation{ 0, Rotation.Yaw, 0 };

	const FVector Direction{ FRotationMatrix{YawRotation}.GetUnitAxis(EAxis::Y) };
	AddMovementInput(Direction, Value);
}

void APlayerChar::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerChar::LookUpRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void APlayerChar::FireWeapon()
{
}

void APlayerChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerChar::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerChar::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerChar::TurnAtRate);
	PlayerInputComponent->BindAxis("Lookup", this, &APlayerChar::LookUpRate);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("FireButton", IE_Pressed, this, &APlayerChar::FireWeapon);
}

