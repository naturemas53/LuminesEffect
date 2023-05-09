// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../../../InGameCommon.h"
#include "BlockView.generated.h"

class UBlock;

/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API UBlockView : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	/*!
	 @brief ����������
	*/
	void InitializeView(UBlock* refBlock)
	{
		// ���̏��A���ł�邱�Ƃ͓��ɂȂ��̂ŁA���̂܂ܔh����֊ۓ���.
		InitializeImpl( refBlock );
		InitializeImplOnBP();
	};

	/*!
	* @brief ��View���Ή����Ă���u���b�N��ނ̃Q�b�^�[.
	*/
	virtual EBlockType GetTargetBlockType() { return EBlockType::BLOCK_NONE; }

protected:
	/*!
	 @brief �����ł̏���������
	*/
	virtual void InitializeImpl(UBlock* refBlock) {};

	/*!
	 @brief �����ł�"�u���[�v�����g��"�̏���������
	*/
	UFUNCTION(BlueprintNativeEvent)
	void InitializeImplOnBP();

	/*!
	 @brief �����ł�"�u���[�v�����g��"�̏�����������[C++��]
	        ...�́H�@�Ǝv����������Ȃ����A�ǂ���BlueprintNativeEvent���������ꍇ�A
			C++������`����K�v������͗l.(�Q�l��: http://kagring.blog.fc2.com/blog-entry-780.html )
			���ł͓��ɉ������Ȃ�.
	*/
	virtual void InitializeImplOnBP_Implementation() {};
};
