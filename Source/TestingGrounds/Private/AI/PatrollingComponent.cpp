// Fill out your copyright notice in the Description page of Project Settings.

#include "PatrollingComponent.h"

UPatrollingComponent::UPatrollingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

TArray<AActor*> UPatrollingComponent::GetPatrolPoints() const
{
	return PatrolPoints;
}

