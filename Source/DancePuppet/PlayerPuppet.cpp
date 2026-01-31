// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPuppet.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
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

	}
}


// Called whenever you do move input.
void APlayerPuppet::MoveInput(const FInputActionValue& InputValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Blue, TEXT("MoveInput has been called!"));
	
	
}
