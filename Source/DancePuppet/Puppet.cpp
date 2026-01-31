// Fill out your copyright notice in the Description page of Project Settings.


#include "Puppet.h"

// Sets default values
APuppet::APuppet()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

float APuppet::GetHealth() const
{
	return Health;
}

void APuppet::SetHealth(float InHealth)
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

void APuppet::TakeDamage(float InDamage)
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



