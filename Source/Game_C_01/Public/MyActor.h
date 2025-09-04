#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class GAME_C_01_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

private:
    FVector2D CurrentLocation;
    FVector2D PreviousLocation;

    float  TotalDistance;
    int32  TotalEventCount;

    int32  Step() const;                             
    void   Move(int32 MoveCount);                    
    void   TriggerEventWithProbability(float Probability); 
    static float Distance(const FVector2D& A, const FVector2D& B); 
};
