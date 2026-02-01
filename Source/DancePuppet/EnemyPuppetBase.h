// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Puppet.h"
#include "EnemyPuppetBase.generated.h"

/**
 * 
 */
UCLASS()
class DANCEPUPPET_API AEnemyPuppetBase : public APuppet
{
	GENERATED_BODY()
	
protected:
	
	
	virtual void Die() override;
	
};
