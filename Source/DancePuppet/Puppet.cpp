// Fill out your copyright notice in the Description page of Project Settings.


#include "Puppet.h"
#include "Components/BoxComponent.h"

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
}

void APuppet::BasicAttack()
{
	// Override this in the children too
	
	PlayAttack1Animation();
	
	GetWorld()->GetTimerManager().SetTimer(PuppetTimerHandle, this, &APuppet::Attack1HitDetection, Attack1HitDelay, false);
	
}

void APuppet::Attack1HitDetection()
{
	
	if (BasicAttackHitbox)
	{
		TArray<AActor*> OverlappingActors;
		BasicAttackHitbox->GetOverlappingActors(OverlappingActors);
		for (AActor* OverlappingActor : OverlappingActors)
		{
			TObjectPtr<APuppet> PuppetPtr;
			if (PuppetPtr = Cast<APuppet> OverlappingActor)
			{
				// Deals damage
				PuppetPtr->PuppetTakeDamage(Damage);
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Attack hit!"));
				return;
			}
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Attack hitbox is not valid!"));
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Blue, TEXT("Attack missed!"));
	
}



