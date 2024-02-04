

#include "InteractiveComponent.h"
#include "CPPComponent/Public/InteractiveComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UInteractiveComponent::UInteractiveComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;
	RayCastLength = 1500.f;
	RayCastRadius = 5.f;
	
}


void UInteractiveComponent::BeginPlay()
{
	Super::BeginPlay();

	
	
}


void UInteractiveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector ActorLocation = CurrentObject->GetActorLocation();
	FVector ActorStartLocation(ActorLocation.X+RayCastStartLocationOffset.X,ActorLocation.Y+RayCastStartLocationOffset.Y,ActorLocation.Z+RayCastStartLocationOffset.Z);
	FVector ActorEndLocation = (CurrentObject->GetActorForwardVector()*RayCastLength)+ActorStartLocation;
	FHitResult OutHit;

	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(CurrentObject);
	bool Hit = UKismetSystemLibrary::SphereTraceSingle(this,
		ActorStartLocation,
		ActorEndLocation,
		RayCastRadius,
		TraceTypeQuery1,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,OutHit,
		true,
		FLinearColor::Green,
		FLinearColor::Red,
		0.f);

	if(Hit)
	{
		GEngine->AddOnScreenDebugMessage(-1,60,FColor::Orange,FString::Printf(TEXT("Casting")));
		RaycastHitingObject = Hit;
	}
}
void UInteractiveComponent::Interactive()
{
	if(RaycastHitingObject)
	{
		UE_LOG(LogTemp,Warning,TEXT("Hit"));
	}
}


