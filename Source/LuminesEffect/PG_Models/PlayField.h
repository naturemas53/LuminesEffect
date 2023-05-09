// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../InGameCommon.h"
#include "Blocks/Block.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayField.generated.h"

DECLARE_DELEGATE_TwoParams(FSetBlockDelegate, UBlock*, int32)
UCLASS()
class LUMINESEFFECT_API APlayField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayField();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/*!
	 @brief 初期化処理
	*/
	UFUNCTION(BlueprintCallable)
	void Initialize(FIntPoint makeInSize);

	/*!
	 @brief リセット　初期化と異なるのは、こちらはフィールド内のリセットのみ.
	*/
	void Reset();

public: // ゲッター&セッター系列

	/*!
	 @brief ブロックをフィールド内にセットします.
	*/
	void SetBlock( UBlock* block, int32 setIdx );
	void SetBlock( UBlock* block, FIntPoint setPos ) { SetBlock( block, ConvertFieldPositionToIndex(setPos) ); }

	/*!
	 @brief フィールド内からブロックを取得します.
	        ...パブリック変数 みたいになってるけど、
			配列から単体の取得、なのでまあまだ意味はある...　はず...？
			（でもあんまよくはなさそう　どうしようね）
	*/
	UBlock* GetBlock( int32 getIdx );
	UBlock* GetBlock( FIntPoint getPos ) { return GetBlock( ConvertFieldPositionToIndex( getPos ) ); }

	/*!
	 @brief フィールドサイズのゲッター.
	*/
	FIntPoint GetSize() { return m_Size; }

	/*!
	 @brief インデックスをフィールド内の位置に変換.
	 @return 変換後のフィールド内の位置を返します.
	*/
	FIntPoint ConvertIndexToFieldPosition(int32 convIdx)
	{
		// 未初期化で呼ばれた場合、0で割ってしまうことになるので、(0,0)をとりあえず返す
		if (m_Size.X <= 0) return FIntPoint();

		int32 posX = convIdx % m_Size.X;
		int32 posY = convIdx / m_Size.X;

		return FIntPoint( posX, posY );
	};

	/*!
	 @brief フィールド内の位置をインデックスに変換.
	 @return 変換後のインデックスを返します.
	*/
	int32 ConvertFieldPositionToIndex( FIntPoint convPos )
	{
		// 未初期化で呼ばれた場合、0で割ってしまうことになるので、0をとりあえず返す.
		if (m_Size.X <= 0) return 0;
		// ...無いとは思いたい　が、横幅が範囲外に行っているなら一応クランプ.
		convPos.X = FMath::Clamp<int32>( convPos.X, 0, m_Size.X);

		int32 retIdx = 0;
		retIdx  = convPos.Y * m_Size.X;
		retIdx += convPos.X;

		return retIdx;
	};

	/*!
	 @brief  指定されたPositionがフィールド内か否かを返します.
	 @return フィールド内の位置であればTrue　それ以外はFalseを返します.
	*/
	bool IsValidPosition( FIntPoint checkPos )
	{
		if( checkPos.X < 0 || checkPos.X >= m_Size.X ) return false;
		if( checkPos.Y < 0 || checkPos.Y >= m_Size.Y ) return false;

		// ここまで来たら上下左右どう見ても範囲内におさまっている　はず.
		return true;
	}

public:
	FSetBlockDelegate OnBlockSetDelegate; //!< ブロック設定時　のイベント publicでいいのかなこれ...

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	/*!
	 @brief フィールド初期化時の各箇所のブロックインスタンスを取得.
	*/
	UBlock* GetBlockOfFieldReset( FIntPoint resetPos );

private:

	TArray<UBlock*> m_HaveBlocks; //!< フィールド内のブロック全部

	FIntPoint m_Size; //!< フィールドの大きさ
	FIntPoint m_InSize; //!< フィールドの大きさ
	FIntPoint m_InFieldPos; //!< フィールドの中身の左上位置（≒初めのIdx）

	// 壁や上部スペース分サイズを追加.
	const int32 WALL_HORIZON_NUM = 2; // 左右に１つずつ
	const int32 WALL_BOTTOM_NUM = 1;  // 下部に１つ
	const int32 FIELD_TOP_SPACE = 2;  // 上部の空白部分

};
