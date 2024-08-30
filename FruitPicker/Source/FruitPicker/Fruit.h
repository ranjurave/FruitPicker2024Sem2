// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fruit.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USceneComponent;
class UParticleSystem;

UCLASS()
class FRUITPICKER_API AFruit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFruit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void NotifyActorBeginOverlap(AActor* OtherActor);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "FruitComponents")
		UStaticMeshComponent* FruitMesh;
	UPROPERTY(EditDefaultsOnly, Category = "FruitComponents")
		UBoxComponent* FruitCollisionBox;
	UPROPERTY(EditDefaultsOnly, Category = "FruitComponents")
		USceneComponent* FruitSceneRoot;
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		UParticleSystem* OverlapFX;
};
