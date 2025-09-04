#include "MyActor.h"
#include "Math/UnrealMathUtility.h"

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = false;

    PreviousLocation = FVector2D::ZeroVector;
    CurrentLocation = FVector2D::ZeroVector;

    TotalDistance = 0.f;
    TotalEventCount = 0;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Initial Location (%.0f, %.0f)"),
        CurrentLocation.X, CurrentLocation.Y);

    Move(10); 
}

int32 AMyActor::Step() const
{
    return FMath::RandRange(0, 1); 
}

void AMyActor::Move(int32 MoveCount)
{
    for (int32 i = 0; i < MoveCount; ++i)
    {
        PreviousLocation = CurrentLocation;

        CurrentLocation.X += Step();
        CurrentLocation.Y += Step();

        TriggerEventWithProbability(50.f); 

        const float MovedDistance = Distance(CurrentLocation, PreviousLocation);
        TotalDistance += MovedDistance;

        UE_LOG(LogTemp, Warning,
            TEXT("Step %d: Current (%.0f, %.0f), Moved: %.2f"),
            i + 1, CurrentLocation.X, CurrentLocation.Y, MovedDistance);
    }

    UE_LOG(LogTemp, Warning,
        TEXT("Total Distance: %.2f, Total Event Count: %d"),
        TotalDistance, TotalEventCount);
}

void AMyActor::TriggerEventWithProbability(float Probability)
{
    const int32 RandomValue = FMath::RandRange(1, 100);

    if (RandomValue <= Probability) 
    {
        UE_LOG(LogTemp, Warning, TEXT("Event Occurred"));
        ++TotalEventCount;
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Event Not Occurred"));
    }
}

float AMyActor::Distance(const FVector2D& A, const FVector2D& B)
{
    const float dx = A.X - B.X;
    const float dy = A.Y - B.Y;
    return FMath::Sqrt(dx * dx + dy * dy);
}
