// Fill out your copyright notice in the Description page of Project Settings.


#include "FieldView.h"
#include "../../PG_Models/PlayField.h"

void UFieldView::InitializeView( APlayField* refField )
{
	// HACK: 下記処理は当クラスの役割範囲外.
	// Viewリサイクル用の保持配列、初期化.
	for ( EBlockType blockType = EBlockType::BLOCK_SPACE; blockType < EBlockType::BLOCK_MAX; blockType = (EBlockType)((int32)blockType + 1) )
	{
		m_UnUsedBlockViews.Add( blockType, TArray<UBlockView*>() );
		m_UnUsedBlockViews[blockType].Empty();
	}

	if (refField == nullptr) return;

	m_RefField = refField;

	// BlockView配列の初期化.
	FIntPoint fieldSize = m_RefField->GetSize();
	m_haveBlockViews.Empty();
	m_haveBlockViews.SetNum( fieldSize.X * fieldSize.Y );

	// フィールド内にブロックが設定された際、すぐにViewを切り替えられるようにイベント登録.
	m_RefField->OnBlockSetDelegate.BindUObject( this, &UFieldView::SwapViewOfDataChanged );

	// 初期化時のみ一気につくる.
	for ( int32 i = 0; i < m_haveBlockViews.Num(); ++i )
	{
		SwapViewOfDataChanged(m_RefField->GetBlock(i), i);
	}
}

void UFieldView::SwapViewOfDataChanged(UBlock* changedBlock, int32 swapIdx)
{
	if (swapIdx < 0 || swapIdx >= m_haveBlockViews.Num()) return;

	RecycleBlockView( swapIdx );
	DispNewestBlockView( changedBlock, swapIdx );
}

void UFieldView::RecycleBlockView( int32 recycleIdx )
{
	// SwapViewOfDataChanged内で呼ばれること前提、つまりidxの範囲はチェック済みとします.

	UBlockView* recycleView = m_haveBlockViews[recycleIdx];

	// 初期化時のみあり得る.
	if( recycleView == nullptr ) return;

	RecycleBlockView_BPImpl( recycleView  );
	m_UnUsedBlockViews[recycleView->GetTargetBlockType()].Add( recycleView );

	m_haveBlockViews[recycleIdx] = nullptr;
}

void UFieldView::DispNewestBlockView( UBlock* block, int32 dispIdx )
{
	UBlockView* dispView = nullptr;
	
	bool isExistReuseView = m_UnUsedBlockViews[block->GetBlockType()].Num() > 0;
	if (isExistReuseView)
	{
		dispView = m_UnUsedBlockViews[block->GetBlockType()][0];
		m_UnUsedBlockViews[block->GetBlockType()].RemoveAt(0);
	}
	else
	{
		TSubclassOf<UUserWidget> loadedClass = m_ViewSoftClassies[block->GetBlockType()].LoadSynchronous();
		dispView = CreateWidget<UBlockView>(GetWorld(), loadedClass);
	}

	dispView->InitializeView( block );

	DispNewestBlockView_BPImpl( dispView, m_RefField->ConvertIndexToFieldPosition(dispIdx) );
	m_haveBlockViews[dispIdx] = dispView;
}