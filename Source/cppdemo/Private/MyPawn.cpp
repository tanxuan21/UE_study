// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	this->TestA();
	// ÊµÀý»¯UObject
	TSubclassOf<UMyObject> MySubClassObject = UMyObject::StaticClass();
	MyTestObject = NewObject<UMyObject>(GetWorld(),MySubClassObject);
	if (MyTestObject) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *MyTestObject->GetName());
		UE_LOG(LogTemp,Warning, TEXT("Health: %f"), MyTestObject->MyDataTableStruct.Health);
	}

	this->MyInstance = Cast<UMyGameInstance>(GetWorld()->GetFirstPlayerController()->GetGameInstance());
	UE_LOG(LogTemp, Warning, TEXT("Instance: %d"), MyInstance->MyAPPID);
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPawn::PrintF()
{
}

bool AMyPawn::PrintF1()
{
	return true;
}

void AMyPawn::TestA_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Testa"));
}

int AMyPawn::TestB_Implementation()
{
	return 0;
}

void AMyPawn::TestC_Implementation(const FString& s)
{
}

int AMyPawn::TestD_Implementation(const FString& s)
{
	return 0;
}

void AMyPawn::printTest()
{
}
