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

	virtual void BeginPlay() override; // 游戏运行就执行beginplay
	virtual void Tick(float DeltaTime) override;// 游戏运行每一帧都执行
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;// 当卸载关卡或者游戏退出调用
};
