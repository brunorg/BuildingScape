// Copyright BRG Tecnologia LTDA


#include "OpenDoor.h"

#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume
	// If the ActorThatOpens is in the volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}

}

// Called when the game starts
void UOpenDoor::OpenDoor()
{
	// Find the owning actor
	AActor *Owner = GetOwner();

	// Create a rotator
	FRotator NewRotation = FRotator(0.0f, 90.0f, 0.0f);

	// Set the door rotator
	Owner->SetActorRotation(NewRotation);
}
