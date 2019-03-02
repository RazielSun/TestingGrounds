// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPool.h"

UActorPool::UActorPool()
{
	PrimaryComponentTick.bCanEverTick = false;

}

AActor* UActorPool::Checkout()
{
	if (Pool.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Checkout."), *(GetName()));
		return Pool.Pop();
	}

	UE_LOG(LogTemp, Warning, TEXT("[%s] Checkout... No in pool."), *(GetName()));
	return nullptr;
}

void UActorPool::Return(AActor* ActorToReturn)
{
	if (ActorToReturn == nullptr)
	{
		return;
	}

	Pool.Push(ActorToReturn);
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor returned: %s."), *(GetName()), *(ActorToReturn->GetName()));
}

void UActorPool::Add(AActor* ActorToAdd)
{
	if (ActorToAdd == nullptr)
	{
		return;
	}
	Pool.Push(ActorToAdd);
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor added: %s."), *(GetName()), *(ActorToAdd->GetName()));
}
