// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <Kismet/KismetMathLibrary.h>

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComp");

	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationPitch = false;
}

void ASCharacter::MoveForward(float value) 
{
	FRotator ControllerRotation = GetControlRotation();
	ControllerRotation.Pitch = 0.f;
	ControllerRotation.Roll = 0.f;

	FVector forwardVector = UKismetMathLibrary::GetForwardVector(ControllerRotation);
	AddMovementInput(forwardVector, value);
}

void ASCharacter::MoveSide(float value) 
{
	FRotator ControllerRotation = GetControlRotation();
	ControllerRotation.Pitch = 0.f;
	ControllerRotation.Roll = 0.f;

	FVector rigthVector = UKismetMathLibrary::GetRightVector(ControllerRotation);
	AddMovementInput(rigthVector, value);
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
	PlayerInputComponent->BindAxis("Move Right / Left", this, &ASCharacter::MoveSide);
	
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Lookup", this, &APawn::AddControllerPitchInput);
}
