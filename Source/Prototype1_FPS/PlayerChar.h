
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerChar.generated.h"

UCLASS()
class PROTOTYPE1_FPS_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	
	APlayerChar();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
protected:
	
	virtual void BeginPlay() override;

	//Input
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Rate);
	void LookUpRate(float Rate);
	void FireWeapon();

	

private:
	float BaseTurnRate;
	float BaseLookUpRate;

};
