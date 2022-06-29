
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
		SetActorLocation(GetActorLocation() + (PlatformVelocity * DeltaTime));
	}
}

bool AMovingPlatform::ShouldTurnAround()
{
	return 	FVector::Dist(GetActorLocation(), StartLocation) > MaxMoveValue;
}

void AMovingPlatform::FlipMovement()
{
	const FVector MoveDirection = PlatformVelocity.GetSafeNormal();
	StartLocation = StartLocation + MoveDirection * MaxMoveValue;
	SetActorLocation(StartLocation);
	PlatformVelocity = -PlatformVelocity;
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Rotate Called!"))
}
