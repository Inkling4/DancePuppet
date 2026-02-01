// Fill out your copyright notice in the Description page of Project Settings.


#include "FightGameMode.h"

void AFightGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AFightGameMode::SpawnPuppet, SpawnDelay, true);
	
}
