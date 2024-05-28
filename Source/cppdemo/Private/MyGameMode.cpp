// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
// 游戲模式游戏模式
AMyGameMode::AMyGameMode() {
	this->DefaultPawnClass = AMyPawn::StaticClass();
	this->PlayerControllerClass = AMyPlayerController::StaticClass();
	this->GameStateClass = AMyGameState::StaticClass();
	this->PlayerStateClass = AMyPlayerState::StaticClass();
	this->HUDClass = AMyHUD::StaticClass();
}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
// 虚幻输出文本内容到控制台
	//params参数： 临时日志类别名称，日志记录级别 文本内容
	// 日志记录级别
	// Error Waring Display 级别从大到小
	UE_LOG(LogTemp, Error, TEXT("My name is OK"));
	UE_LOG(LogTemp, Warning, TEXT("My name is OK"));
	UE_LOG(LogTemp, Display, TEXT("My name is OK"));
	// 打印到屏幕上
	// 默认值， 打印时间，打印颜色，文本内容
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("My Name IS OK"));

}

void AMyGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
