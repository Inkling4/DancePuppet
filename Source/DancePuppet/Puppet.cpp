// Fill out your copyright notice in the Description page of Project Settings.


#include "Puppet.h"
#include "Components/BoxComponent.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
APuppet::APuppet()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BasicAttackHitbox = CreateDefaultSubobject<UBoxComponent>("BasicAttackHitbox");
	BasicAttackHitbox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APuppet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuppet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
}

float APuppet::PuppetGetHealth() const
{
	return Health;
}

void APuppet::PuppetSetHealth(float InHealth)
{
	if (InHealth < 0.f)
	{
		Health = 0.f;
	}
	else
	{
		Health = InHealth;
	}
	
	if (Health <= 0.f)
	{
		Die();
	}
}

void APuppet::PuppetTakeDamage(float InDamage)
{
	if (InDamage > Health)
	{
		Health = 0.f;
	}
	else
	{
		Health -= InDamage;
	}
	if (Health <= 0.f)
	{
		Die();
	}
}

void APuppet::BasicAttack()
{
	// Override this in the children too
	
	if (bIsAttacking)
	{
		return;
	}
	
	bIsAttacking = true;
	
	PlayAttack1Animation();
	
	GetWorld()->GetTimerManager().SetTimer(PuppetTimerHandle, this, &APuppet::Attack1HitDetection, Attack1HitDelay, false);
	
}

void APuppet::Attack1HitDetection()
{
	bool bDidItHit = false;
	
	if (BasicAttackHitbox)
	{
		TArray<AActor*> OverlappingActors;
		BasicAttackHitbox->GetOverlappingActors(OverlappingActors);
		for (AActor* OverlappingActor : OverlappingActors)
		{
			TObjectPtr<APuppet> PuppetPtr;
			PuppetPtr = Cast<APuppet>(OverlappingActor);
			if (PuppetPtr)
			{
				// Deals damage
				PuppetPtr->PuppetTakeDamage(Damage);
				// Deals knockback
				FVector Location = GetActorLocation();
				PuppetPtr->PuppetTakeKnockback(Location);
				bDidItHit = true;
			}
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Attack hitbox is not valid!"));
	}
	
	if (bDidItHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, TEXT("Attack hit!"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, TEXT("Attack missed!"));
	}
	
	bIsAttacking = false;
}

void APuppet::PuppetTakeKnockback(FVector KnockbackSourceLocation)
{
	float NewVelocity = 4000.f * KnockbackMult;
	
	FVector VelocityDirection = GetActorLocation() - KnockbackSourceLocation;
	VelocityDirection.Normalize();
	
	
	VelocityDirection *= {NewVelocity, NewVelocity, NewVelocity};
	
	GetMovementComponent()->Velocity = VelocityDirection;
	
}

void APuppet::Die()
{
	// Override in children
	OnDeath(); // Calls blueprint event
}
