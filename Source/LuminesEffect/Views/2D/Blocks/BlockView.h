// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../../../InGameCommon.h"
#include "BlockView.generated.h"

class UBlock;

/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API UBlockView : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	/*!
	 @brief 初期化処理
	*/
	void InitializeView(UBlock* refBlock)
	{
		// 今の所、基底でやることは特にないので、そのまま派生先へ丸投げ.
		InitializeImpl( refBlock );
		InitializeImplOnBP();
	};

	/*!
	* @brief 当Viewが対応しているブロック種類のゲッター.
	*/
	virtual EBlockType GetTargetBlockType() { return EBlockType::BLOCK_NONE; }

protected:
	/*!
	 @brief 内部での初期化処理
	*/
	virtual void InitializeImpl(UBlock* refBlock) {};

	/*!
	 @brief 内部での"ブループリント側"の初期化処理
	*/
	UFUNCTION(BlueprintNativeEvent)
	void InitializeImplOnBP();

	/*!
	 @brief 内部での"ブループリント側"の初期化処理の[C++側]
	        ...は？　と思うかもしれないが、どうもBlueprintNativeEventを書いた場合、
			C++側も定義する必要がある模様.(参考元: http://kagring.blog.fc2.com/blog-entry-780.html )
			基底では特に何もしない.
	*/
	virtual void InitializeImplOnBP_Implementation() {};
};
