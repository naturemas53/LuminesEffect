// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../InGameCommon.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Block.generated.h"

/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API UBlock : public UObject
{
	GENERATED_BODY()

public:
	void Update(float deltaTime);

public:

	void Initialize();

	// MEMO: ���������͂�����������ʃR���|�[�l���g�ɂ�������������������Ȃ�
	//       (�������͂��������A�����̎d�g�ݎ��̂𕨗��Ƃ������AUE�̕��ɔC���Ă��܂��@�Ƃ��H�j
	//       ...���A����͂Ƃ肠�������~�l�X����肽���i�H�j�̂ŁA��U�͊ȒP�ȕ��ō��܂�

	/*!
	 @brief ������L���ɂ��܂�.
	 @return �Ȃ�
	*/
	void SetEnableFall(bool isFall);

	/*!
	 @brief �����i�s�x�̃Q�b�^�[�i�����p�j
	 @return ���̃u���b�N�̗����i�s�x.
	*/
	float GetFallProgress() { return m_FallProgress; }

	/*!
	 @brief ������L���ɂ��邩�ݒ肵�܂�.
	 @return �R���W���������ł����True�@�����łȂ����False��Ԃ��܂�.
	*/
	virtual bool IsHaveCollision() { return m_IsCollision; }

	/*!
	 @brief  �����F�Z�b�^�[.
			 ...�{���͗ǂ��Ȃ����ǁA�Ƃ肠�����{��͂������ł͂Ȃ��̂�.
	*/
	virtual void SetHaveColor(EHaveColor setHaveColor) { m_HaveColor = setHaveColor; }
	/*!
	 @brief  �����F�Q�b�^�[.
	*/
	virtual EHaveColor GetHaveColor() { return m_HaveColor; }

	/*!
	 @brief  �u���b�N��ʂ̃Q�b�^�[.
	*/
	virtual EBlockType GetBlockType() { return EBlockType::BLOCK_NONE; }

protected:

	/*!
	 @brief  �����̏��������� �i��ɔh����ł̏����������̋L�q�j.
	*/
	virtual void InitializeImpl() {};

protected:

	EHaveColor m_HaveColor; //!< �����F.

	float m_FallProgress;   //!< �����i�s�x. 1.0��1�}�X���������ƂɂȂ�.
	bool m_IsFalling; //!< ��������.

	bool m_IsCollision; //!< �R���W���������H.
};
