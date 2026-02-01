// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DANCEPUPPET_API AFightGameMode : public AGameModeBase
{
	GENERATED_BODY()
protected:
	FTimerHandle SpawnTimerHandle;
	
	
	
	
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, category = "Game")
	void SpawnPuppet();
	
public:
	// The time between each puppet spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Game")
	float SpawnDelay = 5.f;
	
};
