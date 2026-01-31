// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPuppet.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"



// Called to bind functionality to input
void APlayerPuppet::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(IMC_PlayerControls, 0);
		}
	}
	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(IA_Move, ETriggerEvent::Triggered, this, &APlayerPuppet::MoveInput);
		Input->BindAction(IA_Attack1, ETriggerEvent::Triggered, this, &APlayerPuppet::Attack1Input);
	}
}


// Called whenever you do move input.
void APlayerPuppet::MoveInput(const FInputActionValue& InputValue)
{
	// GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("MoveInput has been called!"));
	
	FVector2D InputVector = InputValue.Get<FVector2D>();

	if (IsValid(Controller))
	{
		//Get forward direction
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		//Depending on WASD pressed, will move forwards and rightwards
		AddMovementInput(ForwardDirection, InputVector.Y);
		AddMovementInput(RightDirection, InputVector.X);

	}
}

// Called whenever you press the button for attack1 (M1)
void APlayerPuppet::Attack1Input(const FInputActionValue& InputValue)
{
	
	
	// Calls the virtual function in self
	BasicAttack();
}

void APlayerPuppet::BasicAttack()
{
	Super::BasicAttack();
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Basic Attack triggered!"));
}

