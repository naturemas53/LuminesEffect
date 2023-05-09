// Fill out your copyright notice in the Description page of Project Settings.


#include "Block.h"

void UBlock::Initialize()
{
	m_FallProgress = 0.0f;
	m_IsFalling = 0.0f;

	m_HaveColor = EHaveColor::HAVE_COLOR_NONE;
	m_IsCollision = true;

	InitializeImpl();
}

void UBlock::Update(float deltaTime)
{
	if (!m_IsFalling) return;

	m_FallProgress += deltaTime;

	// 1�u���b�N����������.
	if (m_FallProgress >= InGameConsts::FALL_TIME_ONE_BLOCK)
	{
		m_FallProgress -= InGameConsts::FALL_TIME_ONE_BLOCK;

		//TODO: 1�u���b�N���������̃C�x���g����.
	}
}

// �����L���L��
void UBlock::SetEnableFall( bool setFall )
{
	m_IsFalling = setFall;

	// �����������A�������������z�����Z�b�g.
	if ( !m_IsFalling )
	{
		m_FallProgress = 0.0f;
	}
}