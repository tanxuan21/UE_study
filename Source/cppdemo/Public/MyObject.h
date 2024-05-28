// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Classes/Engine/DataTable.h" // ���ݱ��������ͷ�ļ�
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

// ����ǽ���Ecxel���ݱ��Ϊ�ṹ��Ĳ�����ֱ�ӽ�Excel��ק���������ļ��м��ɴ���
USTRUCT(BlueprintType)
struct FMyDataTableStruct :public FTableRowBase{// ���м̳���������
	FMyDataTableStruct();
	GENERATED_USTRUCT_BODY() // һ��Ҫ���������
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "MyTestDataTableStruct")
	float Health;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "MyTestDataTableStruct")
	FString Name;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "MyTestDataTableStruct")
	int32 Level;

};
/**
 * 
 */
UCLASS()
class CPPDEMO_API UMyObject : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FMyDataTableStruct MyDataTableStruct;
};
