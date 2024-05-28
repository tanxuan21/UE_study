// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyObject.h"
#include "GameFramework/Pawn.h"
#include "./MyGameInstance.h"



#include "MyPawn.generated.h"

UENUM(BlueprintType)
namespace MyEnumType {
	enum MyCustomEnum {
		Type1,
		Type2,
		Type3,
	};
}
UENUM(BlueprintType)
enum class EMyTestEnum : uint8 {
	OneType UMETA(DisplayName = "OneType"),
	TwoType UMETA(DisplayName = "TwoType"),
	ThreeType UMETA(DisplayName = "ThreeType"),
};

USTRUCT(BlueprintType)
struct FMyTestStruct { // ������ 'F '��ͷ ��
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyTestStruct")
	int32 Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyTestStruct")
	FString MyName;
};


UCLASS()
class CPPDEMO_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ������ý��������ݽ�cpp����ͼͨ��

	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnlyInt;
	// ������ϸ�����ɼ�
	UPROPERTY(VisibleInstanceOnly)
	FString VisibleInstanceString;
	// ��Ĭ�����ú�ʵ��ϸ����嶼�ɼ�
	UPROPERTY(VisibleAnywhere)
	FVector VisibleAnywherevector;

	UPROPERTY(EditDefaultsOnly)
	int32 EditDefaultsOnlyInt;
	UPROPERTY(EditInstanceOnly)
	FString EditInstanceOnlyString;
	UPROPERTY(EditAnywhere);
	FVector EditAnyWhereVector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 BlueprintReadOnlyInt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BlueprintReadWriteString;

	// CategoryĿ¼
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyIntValue")
	int32 Value1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyIntValue|MySubIntValue")
	int32 Value2;

	// ����
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(DisplayName="MyValue3DisplayName"))
	int32 MyValue3;

	// �����༭
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "controller"))
	bool isController;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(EditCondition="isController"))
	float value3;

	// ����˵������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "isControllerTrue"));
	bool isTrue;



	// ��¶���������ں������߿⺯��������ͼ�пɵ���
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void PrintF();
	// ���麯��
	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyFunction")
	bool PrintF1();
	
	
	
	// ��cpp���������ܶ���.��ͼ������
	// �з���ֵ������Ϊ��һ���������޷���ֵ������Ϊ��һ���¼�
	UFUNCTION(BlueprintImplementableEvent)
	void Test1();
	UFUNCTION(BlueprintImplementableEvent)
	int Test2();
	UFUNCTION(BlueprintImplementableEvent)
	void Test11(const FString &s);
	UFUNCTION(BlueprintImplementableEvent)
	int Test22(const FString &s);



	// ��cpp����������ʵ�֣���ͼ�����ػ��߲�����
	UFUNCTION(BlueprintNativeEvent)
	void TestA();
	UFUNCTION(BlueprintNativeEvent)
	int TestB();
	UFUNCTION(BlueprintNativeEvent)
	void TestC(const FString& s);
	UFUNCTION(BlueprintNativeEvent)
	int TestD(const FString& s);



	// Ԫ����˵����
	UFUNCTION(BlueprintCallable,Category = "MyFunction",meta = (DisplayName = "MyPrintFunction"))
	void printTest();


	// ö��
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "MyEnum")
	TEnumAsByte< MyEnumType::MyCustomEnum> MyCustomEnum;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "MyCustomStruct")
	FMyTestStruct MyCustomStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyEnum")
	EMyTestEnum MyCustomEnum1;

	// ��ͼ����ʱ��¶
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyExposeOnSpawn", meta = (ExposeOnSpawn = "ExposeOnSpawnValue"))
		int MyHealth;

	// ����UObject����,�ڹ��캯����ʵ����
	UPROPERTY()
	UMyObject* MyTestObject;

	// ��Ϸʵ��
	UPROPERTY()
	UMyGameInstance* MyInstance;
};
