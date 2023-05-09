// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceBlock.h"

void USpaceBlock::InitializeImpl()
{
	// MEMO: （クラス名自体が矛盾しちゃってるけど）空白を示すクラスなので
	//       コリジョンは持たせない.
	m_IsCollision = false;
}