// Copyright Epic Games, Inc. All Rights Reserved.

#include "Prototype1_FPSPickUpComponent.h"

UPrototype1_FPSPickUpComponent::UPrototype1_FPSPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UPrototype1_FPSPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UPrototype1_FPSPickUpComponent::OnSphereBeginOverlap);
}

void UPrototype1_FPSPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	APrototype1_FPSCharacter* Character = Cast<APrototype1_FPSCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
