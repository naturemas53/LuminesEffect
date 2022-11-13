// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IngameDefine.generated.h"

UENUM(BlueprintType)
enum class EBlockType : uint8
{
	NONE = 0 UMETA(ToolTip = "どのブロックでもない."),
	SPACE    UMETA(ToolTip = "空き場所"),
	WALL     UMETA(ToolTip = "壁"),
	COLOR_A  UMETA(ToolTip = "1色目"),
	COLOR_B  UMETA(ToolTip = "2色目"),

	MAX UMETA(ToolTip = "この列挙型の最大要素数"),

	LOOP_START = SPACE UMETA(ToolTip = "この列挙型のループ開始"),
	LOOP_END = MAX - 1 UMETA(ToolTip = "この列挙型のループ終了"),
};

USTRUCT(BlueprintType)
struct FPiece
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EBlockType> blocks;
};
