// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../../PG_Models/PlayField.h"
#include "Blocks/BlockView.h"
#include "FieldView.generated.h"

class UBlock;
/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API UFieldView : public UUserWidget
{
	GENERATED_BODY()

public:

	/*!
	 @brief 初期化処理.
	 @param[in] initializedField 参照元のField（※ただし、初期化済み（≒サイズ設定済み）とします！）
	*/
	UFUNCTION(BlueprintCallable)
	void InitializeView( APlayField* initializedField );

	/*!
	 @brief 参照中のフィールド のサイズを返す関数.
	*/
	UFUNCTION(BlueprintPure)
	FIntPoint GetRefFieldSize()
	{
		if( m_RefField == nullptr ) return FIntPoint();

		return m_RefField->GetSize();
	}

private:
	
	/*!
	 @brief フィールド内のブロック変更時に対応して、Viewを変更させる処理.
	*/
	void SwapViewOfDataChanged( UBlock* changedBlock, int32 swapIdx );

	/*!
	 @brief ブロック変更等で使用しなくなるViewを非表示にして保持します.
	*/
	void RecycleBlockView( int32 recycleIdx );

	/*!
	 @brief 指定箇所のブロックViewを変更します.
	*/
	void DispNewestBlockView(UBlock* dispBlock, int32 dispIdx);


public:
	/*!
		@brief ブロック変更等で使用しなくなるViewを非表示にして保持します.
			   ...が、その時のBP側の処理です.（Canvasからのデタッチとか）.
	*/
	UFUNCTION(BlueprintImplementableEvent)
		void RecycleBlockView_BPImpl(UBlockView* recycleView);
	/*!
		@brief 指定箇所のブロックViewを変更...　する際の、BP側の処理です（Canvasアタッチとか？）.
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void DispNewestBlockView_BPImpl(UBlockView* blockView, FIntPoint fieldPos);

private:
	APlayField* m_RefField = nullptr; //!< 参照先のフィールド.

	TArray< UBlockView* > m_haveBlockViews; //!< 自Viewを構成しているBlockViewの集まり.
	TMap< EBlockType, TArray<UBlockView*> > m_UnUsedBlockViews; //!< 未使用のブロックView HACK:...これ多分他クラスじゃないすかね

protected:
	UPROPERTY(BlueprintReadWrite)
	TMap< EBlockType, TSoftClassPtr<UBlockView> > m_ViewSoftClassies; //!< 各ブロックとViewの結びつけ.
};
