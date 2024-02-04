// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractiveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPPCOMPONENT_API UInteractiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractiveComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "RayCast")
	AActor* CurrentObject;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "RayCast")
	FVector RayCastStartLocationOffset;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "RayCast")
	float RayCastLength;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "RayCast")
	float RayCastRadius;
	
	UFUNCTION(BlueprintCallable,Category="RayCastInteractive")
	void Interactive();

	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	bool bCanInterActive;

private:
	bool bRaycastHitingObject;

	void SphereTraceSingle();
};
