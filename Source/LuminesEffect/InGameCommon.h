// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace InGameConsts
{

	const float FALL_TIME_ONE_BLOCK = 1.0f; //!< 1�u���b�N������܂ł̎���.

}

UENUM(BlueprintType, Category = "InGame")
enum class EBlockType : uint8
{
	BLOCK_NONE,   //!< ����`�i��{�g�p���Ȃ��I�j.
	BLOCK_SPACE,  //!< ��.
	BLOCK_WALL,   //!< ��.
	BLOCK_NORMAL, //!< �ʏ�u���b�N.

	BLOCK_MAX,    //!< �u���b�N��ސ�.
};

UENUM(BlueprintType, Category = "InGame")
enum class EHaveColor : uint8
{
	HAVE_COLOR_NONE, //!< ������.
	HAVE_COLOR_A,    //!< �J���[A������.
	HAVE_COLOR_B,    //!< �J���[B������.

	HAVE_COLOR_MAX   //!< �����F�̎�ސ�.
};
