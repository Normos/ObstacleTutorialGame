#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSUALT_API AMovingPlatform final : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Movement")
	FVector PlatformVelocity = FVector(100,0,0);

	UPROPERTY(EditAnywhere, Category="Movement")
	float MaxMoveValue = 100.0f;
	
	UPROPERTY(EditAnywhere, Category="Rotation")
    FRotator RotationVelocity;
	

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool ShouldTurnAround() const;
	double GetDistanceMoved() const;
	void FlipMovement();
};
