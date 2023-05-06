// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "WallBlock.generated.h"

/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API UWallBlock : public UBlock
{
	GENERATED_BODY()
	
public:

	EBlockType GetBlockType() override { return EBlockType::BLOCK_WALL; }


	// MEMO: �F���������Ȃ��ׂɓ���������܂�.
	void SetHaveColor(EHaveColor setHaveColor) override { return; }

};
