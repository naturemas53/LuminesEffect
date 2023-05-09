// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalBlockView.h"

void UNormalBlockView::InitializeImpl(UBlock* refBlock)
{
	m_refBlock = nullptr;

	if (refBlock->GetBlockType() == EBlockType::BLOCK_NORMAL)
	{
		m_refBlock = refBlock;
	}
}