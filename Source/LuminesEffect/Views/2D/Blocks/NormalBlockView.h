// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlockView.h"
#include "../../../PG_Models/Blocks/Block.h"
#include "../../../InGameCommon.h"
#include "NormalBlockView.generated.h"

#define BLOCK_DATA_CHECK(retValue) if( m_refBlock == nullptr ) return (retValue);

/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API UNormalBlockView : public UBlockView
{
	GENERATED_BODY()
	
public:

	/*!
	* @brief 当Viewが対応しているブロック種類のゲッター.
	*/
	EBlockType GetTargetBlockType() override { return EBlockType::BLOCK_NORMAL; } 

protected:
	/*!
	 @brief 内部での初期化処理
	*/
	void InitializeImpl(UBlock* refBlock) override;

	/*!
	 @brief 落下進行度を取得（主にBP向け）
	*/
	UFUNCTION(BlueprintPure)
	float GetFallProgress()
	{
		BLOCK_DATA_CHECK(0.0f)

		return m_refBlock->GetFallProgress();
	}

	/*!
	 @brief 所持色を取得（主にBP向け）
	*/
	UFUNCTION(BlueprintPure)
	EHaveColor GetHaveColor()
	{
		BLOCK_DATA_CHECK(EHaveColor::HAVE_COLOR_NONE)

		return m_refBlock->GetHaveColor();
	}

private:

	UBlock* m_refBlock = nullptr; //!< 自身が表示対象としているブロック.
};
