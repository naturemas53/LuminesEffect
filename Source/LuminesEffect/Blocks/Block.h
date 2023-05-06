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

	// MEMO: 落下部分はもしかしたら別コンポーネントにした方がいいかもしれない
	//       (もしくはそもそも、落下の仕組み自体を物理というか、UEの物に任せてしまう　とか？）
	//       ...が、今回はとりあえずルミネスを作りたい（？）ので、一旦は簡単な方で作ります

	/*!
	 @brief 落下を有効にします.
	 @return なし
	*/
	void SetEnableFall(bool isFall);

	/*!
	 @brief 落下進行度のゲッター（同期用）
	 @return このブロックの落下進行度.
	*/
	float GetFallProgress() { return m_FallProgress; }

	/*!
	 @brief 落下を有効にするか設定します.
	 @return コリジョン持ちであればTrue　そうでなければFalseを返します.
	*/
	virtual bool IsHaveCollision() { return m_IsCollision; }

	/*!
	 @brief  所持色セッター.
			 ...本当は良くないけど、とりあえず本題はこっちではないので.
	*/
	virtual void SetHaveColor(EHaveColor setHaveColor) { m_HaveColor = setHaveColor; }
	/*!
	 @brief  所持色ゲッター.
	*/
	virtual EHaveColor GetHaveColor() { return m_HaveColor; }

	/*!
	 @brief  ブロック種別のゲッター.
	*/
	virtual EBlockType GetBlockType() { return EBlockType::BLOCK_NONE; }

protected:

	/*!
	 @brief  内部の初期化処理 （主に派生先での初期化処理の記述）.
	*/
	virtual void InitializeImpl() {};

protected:

	EHaveColor m_HaveColor; //!< 所持色.

	float m_FallProgress;   //!< 落下進行度. 1.0で1マス落ちたことになる.
	bool m_IsFalling; //!< 落下中か.

	bool m_IsCollision; //!< コリジョン持ち？.
};
