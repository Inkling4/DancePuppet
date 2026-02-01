// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPuppetBase.h"


void AEnemyPuppetBase::Die()
{
	Super::Die();
	Destroy();
}
