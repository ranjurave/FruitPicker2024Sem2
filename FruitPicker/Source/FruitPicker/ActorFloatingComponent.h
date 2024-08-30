// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorFloatingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FRUITPICKER_API UActorFloatingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorFloatingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	USceneComponent* ActorRoot;

	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
		bool bHoverActor;

	UPROPERTY(EditAnywhere, Category = "Movement")
		bool bRotateActor;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bHoverActor"), Category="Movement")
		float HoverAmplitude;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bHoverActor"), Category = "Movement")
		float HoverSpeed;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bRotateActor"), Category = "Movement")
		float RotateSpeed;	
	
};
