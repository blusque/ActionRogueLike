// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComp");

	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ASCharacter::MoveForward(float value) 
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ASCharacter::MoveSide(float value) 
{
	AddMovementInput(GetActorRightVector(), value);
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &APawn::AddControllerYawInput);
}
