// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPawn.h"
#include "MyPlayerController.h"
#include "MyPlayerState.h"
#include "MyGameState.h"
#include "MyHUD.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CPPDEMO_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()
	AMyGameMode();

	virtual void BeginPlay() override; // ��Ϸ���о�ִ��beginplay
	virtual void Tick(float DeltaTime) override;// ��Ϸ����ÿһ֡��ִ��
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;// ��ж�عؿ�������Ϸ�˳�����
};
