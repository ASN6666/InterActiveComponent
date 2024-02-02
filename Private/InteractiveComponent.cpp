// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveComponent.h"
#include "CPPComponent/Public/InteractiveComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UInteractiveComponent::UInteractiveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	RayCastLength = 1500.f;
	RayCastRadius = 5.f;
	// ...
}


// Called when the game starts
void UInteractiveComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
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
		GEngine->AddOnScreenDebugMessage(123,60,FColor::Orange,FString::Printf(TEXT("Casting")));
	}
}

