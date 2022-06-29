
#include "MovingPlatform.h"

#include <Windows.Media.Capture.h>

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldTurnAround())
	{
		FlipMovement();
	}
	else
	{
		// Move Platform according to set settings
		SetActorLocation(GetActorLocation() + PlatformVelocity * DeltaTime);
	}
}

void AMovingPlatform::FlipMovement()
{
	const FVector MoveDirection = PlatformVelocity.GetSafeNormal();

	// Correct for Overshoot
	StartLocation = StartLocation + MoveDirection * MaxMoveValue;
	SetActorLocation(StartLocation);

	// Flip Vector
	PlatformVelocity = -PlatformVelocity;
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Rotate Called!"))
}

bool AMovingPlatform::ShouldTurnAround() const
{
	return 	GetDistanceMoved() > MaxMoveValue;
}

double AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(GetActorLocation(), StartLocation);
}