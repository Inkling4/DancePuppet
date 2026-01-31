// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Puppet.h"
#include "PlayerPuppet.generated.h"

/**
 * 
 */

// Forward declarations
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class DANCEPUPPET_API APlayerPuppet : public APuppet
{
	GENERATED_BODY()
	
protected: 
	
	// Health regenerated per second
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
	float RegenRate;
	
	float MaxHealth;
	virtual void BeginPlay() override;
	// If true, passive regen is enabled.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	bool bRegenEnabled = true;
	// Input:
	UPROPERTY(EditAnywhere, category = "Input")
	UInputMappingContext* IMC_PlayerControls;
	UPROPERTY(EditAnywhere, category = "Input")
	UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, category = "Input")
	UInputAction* IA_Attack1;
	void MoveInput(const FInputActionValue& InputValue);
	void Attack1Input(const FInputActionValue& InputValue);
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void BasicAttack() override;
	
public: 
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
	
};
