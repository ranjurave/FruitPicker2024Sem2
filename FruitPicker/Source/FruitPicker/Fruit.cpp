// Fill out your copyright notice in the Description page of Project Settings.


#include "Fruit.h"
#include "Components/BoxComponent.h"
#include "FruitPickerCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFruit::AFruit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FruitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FruitMesh"));
	FruitCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("FruitCollisionBox"));
	FruitSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FruitSceneRoot"));

	RootComponent = FruitSceneRoot;
	FruitMesh->SetupAttachment(FruitSceneRoot);
	FruitCollisionBox->SetupAttachment(FruitSceneRoot);

	FruitMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FruitCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	FruitCollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	FruitCollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

// Called when the game starts or when spawned
void AFruit::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFruit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFruit::NotifyActorBeginOverlap(AActor* OtherActor) {
	//UE_LOG(LogTemp, Warning, TEXT("Overlap...."))

	AFruitPickerCharacter* OverlappedActor;

	OverlappedActor = Cast<AFruitPickerCharacter>(OtherActor);

	if (OverlappedActor) {
		OverlappedActor->FruitsPicked++;
		UGameplayStatics::SpawnEmitterAtLocation(this, OverlapFX, GetActorLocation());
		Destroy();
	}
}
