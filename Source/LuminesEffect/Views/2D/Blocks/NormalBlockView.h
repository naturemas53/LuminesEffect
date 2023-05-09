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
	* @brief ��View���Ή����Ă���u���b�N��ނ̃Q�b�^�[.
	*/
	EBlockType GetTargetBlockType() override { return EBlockType::BLOCK_NORMAL; } 

protected:
	/*!
	 @brief �����ł̏���������
	*/
	void InitializeImpl(UBlock* refBlock) override;

	/*!
	 @brief �����i�s�x���擾�i���BP�����j
	*/
	UFUNCTION(BlueprintPure)
	float GetFallProgress()
	{
		BLOCK_DATA_CHECK(0.0f)

		return m_refBlock->GetFallProgress();
	}

	/*!
	 @brief �����F���擾�i���BP�����j
	*/
	UFUNCTION(BlueprintPure)
	EHaveColor GetHaveColor()
	{
		BLOCK_DATA_CHECK(EHaveColor::HAVE_COLOR_NONE)

		return m_refBlock->GetHaveColor();
	}

private:

	UBlock* m_refBlock = nullptr; //!< ���g���\���ΏۂƂ��Ă���u���b�N.
};
