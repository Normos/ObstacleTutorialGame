
#include "MovingPlatform.h"

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
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	float const DistanceMoved = FVector::Dist(CurrentLocation, StartLocation);

	if (DistanceMoved > MaxMoveValue)
	{
		FlipMovement();
		LogOvershoot(DistanceMoved);
	}
}

void AMovingPlatform::FlipMovement()
{
	const FVector MoveDirection = PlatformVelocity.GetSafeNormal();
	StartLocation = StartLocation + MoveDirection * MaxMoveValue;
	SetActorLocation(StartLocation);
	PlatformVelocity = -PlatformVelocity;
}

void AMovingPlatform::LogOvershoot(float const DistanceMoved)
{
	const float Overshoot = DistanceMoved - MaxMoveValue;
	UE_LOG(LogTemp, Display, TEXT("Overshoot [%s] Distance: %f"), *GetName(), Overshoot);
}
