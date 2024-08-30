// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorFloatingComponent.h"

// Sets default values for this component's properties
UActorFloatingComponent::UActorFloatingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActorFloatingComponent::BeginPlay()
{
	Super::BeginPlay();

	ActorRoot = GetOwner()->GetRootComponent();
	StartLocation = GetOwner()->GetActorLocation();
}


// Called every frame
void UActorFloatingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bHoverActor) {
		FVector NewLocation = ActorRoot->GetRelativeLocation();
		float RunningTime = GetOwner()->GetGameTimeSinceCreation();
		float DeltaHeight = (FMath::Sin(RunningTime + HoverAmplitude/100.0f + DeltaTime) - FMath::Sin(RunningTime - HoverAmplitude/100.0f));
		NewLocation.Z += DeltaHeight * HoverSpeed; //Scale our height by a factor of 20
		ActorRoot->SetWorldLocation(NewLocation);
	}
	if (bRotateActor) {
		FRotator NewRotation = ActorRoot->GetRelativeRotation();
		float DeltaRotation = DeltaTime * RotateSpeed;	//Rotate by 20 degrees per second
		NewRotation.Yaw += DeltaRotation;
		ActorRoot->SetWorldRotation(NewRotation);
	}
}

