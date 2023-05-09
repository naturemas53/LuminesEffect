// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Block.h"
#include "NormalBlock.generated.h"

/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API UNormalBlock : public UBlock
{
	GENERATED_BODY()
public:

	EBlockType GetBlockType() override { return EBlockType::BLOCK_NORMAL; }

};
