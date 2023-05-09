// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlockView.h"
#include "SpaceBlockView.generated.h"

/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API USpaceBlockView : public UBlockView
{
	GENERATED_BODY()
	
public:
	/*!
	* @brief ��View���Ή����Ă���u���b�N��ނ̃Q�b�^�[.
	*/
	EBlockType GetTargetBlockType() override { return EBlockType::BLOCK_SPACE; } 

};
