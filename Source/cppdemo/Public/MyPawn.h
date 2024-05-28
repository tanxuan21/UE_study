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
struct FMyTestStruct { // 必须是 'F '开头 。
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

	// 就是虚幻将反射数据将cpp和蓝图通信

	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultsOnlyInt;
	// 仅仅在细节面板可见
	UPROPERTY(VisibleInstanceOnly)
	FString VisibleInstanceString;
	// 类默认设置和实例细节面板都可见
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

	// Category目录
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyIntValue")
	int32 Value1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyIntValue|MySubIntValue")
	int32 Value2;

	// 别名
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(DisplayName="MyValue3DisplayName"))
	int32 MyValue3;

	// 条件编辑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "controller"))
	bool isController;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(EditCondition="isController"))
	float value3;

	// 解释说明变量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ToolTip = "isControllerTrue"));
	bool isTrue;



	// 暴露函数（类内函数或者库函数）在蓝图中可调用
	UFUNCTION(BlueprintCallable, Category = "MyFunction")
	void PrintF();
	// 纯虚函数
	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "MyFunction")
	bool PrintF1();
	
	
	
	// 在cpp声明，不能定义.蓝图可重载
	// 有返回值的重载为是一个函数，无返回值的重载为是一个事件
	UFUNCTION(BlueprintImplementableEvent)
	void Test1();
	UFUNCTION(BlueprintImplementableEvent)
	int Test2();
	UFUNCTION(BlueprintImplementableEvent)
	void Test11(const FString &s);
	UFUNCTION(BlueprintImplementableEvent)
	int Test22(const FString &s);



	// 在cpp中声明或者实现，蓝图可重载或者不重载
	UFUNCTION(BlueprintNativeEvent)
	void TestA();
	UFUNCTION(BlueprintNativeEvent)
	int TestB();
	UFUNCTION(BlueprintNativeEvent)
	void TestC(const FString& s);
	UFUNCTION(BlueprintNativeEvent)
	int TestD(const FString& s);



	// 元数据说明符
	UFUNCTION(BlueprintCallable,Category = "MyFunction",meta = (DisplayName = "MyPrintFunction"))
	void printTest();


	// 枚举
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "MyEnum")
	TEnumAsByte< MyEnumType::MyCustomEnum> MyCustomEnum;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "MyCustomStruct")
	FMyTestStruct MyCustomStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyEnum")
	EMyTestEnum MyCustomEnum1;

	// 蓝图生成时暴露
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyExposeOnSpawn", meta = (ExposeOnSpawn = "ExposeOnSpawnValue"))
		int MyHealth;

	// 创建UObject变量,在构造函数内实例化
	UPROPERTY()
	UMyObject* MyTestObject;

	// 游戏实例
	UPROPERTY()
	UMyGameInstance* MyInstance;
};
