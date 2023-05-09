// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace InGameConsts
{

	const float FALL_TIME_ONE_BLOCK = 1.0f; //!< 1ブロック落ちるまでの時間.

}

UENUM(BlueprintType, Category = "InGame")
enum class EBlockType : uint8
{
	BLOCK_NONE,   //!< 未定義（基本使用しない！）.
	BLOCK_SPACE,  //!< 空白.
	BLOCK_WALL,   //!< 壁.
	BLOCK_NORMAL, //!< 通常ブロック.

	BLOCK_MAX,    //!< ブロック種類数.
};

UENUM(BlueprintType, Category = "InGame")
enum class EHaveColor : uint8
{
	HAVE_COLOR_NONE, //!< 未所持.
	HAVE_COLOR_A,    //!< カラーAを所持.
	HAVE_COLOR_B,    //!< カラーBを所持.

	HAVE_COLOR_MAX   //!< 所持色の種類数.
};
