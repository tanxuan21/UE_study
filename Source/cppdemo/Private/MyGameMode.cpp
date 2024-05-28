// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
// �Α�ģʽ��Ϸģʽ
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
// �������ı����ݵ�����̨
	//params������ ��ʱ��־������ƣ���־��¼���� �ı�����
	// ��־��¼����
	// Error Waring Display ����Ӵ�С
	UE_LOG(LogTemp, Error, TEXT("My name is OK"));
	UE_LOG(LogTemp, Warning, TEXT("My name is OK"));
	UE_LOG(LogTemp, Display, TEXT("My name is OK"));
	// ��ӡ����Ļ��
	// Ĭ��ֵ�� ��ӡʱ�䣬��ӡ��ɫ���ı�����
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
