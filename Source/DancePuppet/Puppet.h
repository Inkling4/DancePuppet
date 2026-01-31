// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Puppet.generated.h"

class UBoxComponent;

UCLASS()
class DANCEPUPPET_API APuppet : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APuppet();

protected:
	
	FTimerHandle PuppetTimerHandle;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay();
	
	// Hit detection for basic attack
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	TObjectPtr<UBoxComponent> BasicAttackHitbox;
	
	// The delay between when attack starts and when the hit detection happens.
	// For animation synchronization purposes.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	float Attack1HitDelay = 0.33f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, category = "Combat")
	bool bIsAttacking = false;
    	
	// Properties
	UPROPERTY(EditAnywhere, category = "Status")
	float Health = 3.f;
	// The damage this puppet deals per basic attack.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Status")
	float Damage = 1.f;
	// Knockback multiplier on self
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Status")
	float KnockbackMult = 1.f;
	
	
	// Does a basic attack. Has no functionality in the base class, please override.
	UFUNCTION(BlueprintCallable, Category = "Status")
	virtual void BasicAttack();
	
	
	
	UFUNCTION(BlueprintImplementableEvent, category = "Puppet Animations")
	void PlayAttack1Animation();
	
	// Checks hitbox and deals damage
	void Attack1HitDetection();
	
	// Called when going to die
	UFUNCTION(BLueprintCallable, Category = "Status")
	virtual void Die();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Returns the current health of this character
	UFUNCTION(BlueprintCallable, Category = "Status")
	float PuppetGetHealth() const;
	// Sets health of this puppet to the new value
	UFUNCTION(BlueprintCallable, Category = "Status")
	void PuppetSetHealth(float InHealth);
	// Removes health by input damage
	UFUNCTION(BlueprintCallable, Category = "Status")
	void PuppetTakeDamage(float InDamage);
	// Gets knocked back from source location.
	void PuppetTakeKnockback(FVector KnockbackSourceLocation);
	
	

};
