// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypointTask.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingComponent.h"

EBTNodeResult::Type UChooseNextWaypointTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto ControllerPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolComp = ControllerPawn->FindComponentByClass<UPatrollingComponent>();

	if (!ensure(PatrolComp))
	{
		return EBTNodeResult::Failed;
	}
		
	auto PatrolPoints = PatrolComp->GetPatrolPoints();

	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s PatrolRoute is empty!!!"), *(ControllerPawn->GetName()));
		return EBTNodeResult::Failed;
	}

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	if (PatrolPoints.Num() > 0)
	{
		BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

		Index++;
		Index = Index % PatrolPoints.Num();
		BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);
	}

	//UE_LOG(LogTemp, Warning, TEXT("AI in C++! %i"), Index);

	return EBTNodeResult::Succeeded;
}