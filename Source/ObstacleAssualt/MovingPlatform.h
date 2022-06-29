#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSUALT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100,0,0);

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MaxMoveValue = 100.0f;

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool ShouldTurnAround();
	void FlipMovement();
};
