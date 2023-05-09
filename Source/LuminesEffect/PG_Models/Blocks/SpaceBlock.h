// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "SpaceBlock.generated.h"

/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API USpaceBlock : public UBlock
{
	GENERATED_BODY()

public:

	EBlockType GetBlockType() override { return EBlockType::BLOCK_SPACE; }

	// MEMO: F‚ğ‚½‚¹‚È‚¢ˆ×‚É“®ì‚ğÁ‚µ‚Ü‚·.
	void SetHaveColor(EHaveColor setHaveColor) override { return; }

protected:
	
	void InitializeImpl() override;
	
};
