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
	 @brief ����������
	*/
	UFUNCTION(BlueprintCallable)
	void Initialize(FIntPoint makeInSize);

	/*!
	 @brief ���Z�b�g�@�������ƈقȂ�̂́A������̓t�B�[���h���̃��Z�b�g�̂�.
	*/
	void Reset();

public: // �Q�b�^�[&�Z�b�^�[�n��

	/*!
	 @brief �u���b�N���t�B�[���h���ɃZ�b�g���܂�.
	*/
	void SetBlock( UBlock* block, int32 setIdx );
	void SetBlock( UBlock* block, FIntPoint setPos ) { SetBlock( block, ConvertFieldPositionToIndex(setPos) ); }

	/*!
	 @brief �t�B�[���h������u���b�N���擾���܂�.
	        ...�p�u���b�N�ϐ� �݂����ɂȂ��Ă邯�ǁA
			�z�񂩂�P�̂̎擾�A�Ȃ̂ł܂��܂��Ӗ��͂���...�@�͂�...�H
			�i�ł�����܂悭�͂Ȃ������@�ǂ����悤�ˁj
	*/
	UBlock* GetBlock( int32 getIdx );
	UBlock* GetBlock( FIntPoint getPos ) { return GetBlock( ConvertFieldPositionToIndex( getPos ) ); }

	/*!
	 @brief �t�B�[���h�T�C�Y�̃Q�b�^�[.
	*/
	FIntPoint GetSize() { return m_Size; }

	/*!
	 @brief �C���f�b�N�X���t�B�[���h���̈ʒu�ɕϊ�.
	 @return �ϊ���̃t�B�[���h���̈ʒu��Ԃ��܂�.
	*/
	FIntPoint ConvertIndexToFieldPosition(int32 convIdx)
	{
		// ���������ŌĂ΂ꂽ�ꍇ�A0�Ŋ����Ă��܂����ƂɂȂ�̂ŁA(0,0)���Ƃ肠�����Ԃ�
		if (m_Size.X <= 0) return FIntPoint();

		int32 posX = convIdx % m_Size.X;
		int32 posY = convIdx / m_Size.X;

		return FIntPoint( posX, posY );
	};

	/*!
	 @brief �t�B�[���h���̈ʒu���C���f�b�N�X�ɕϊ�.
	 @return �ϊ���̃C���f�b�N�X��Ԃ��܂�.
	*/
	int32 ConvertFieldPositionToIndex( FIntPoint convPos )
	{
		// ���������ŌĂ΂ꂽ�ꍇ�A0�Ŋ����Ă��܂����ƂɂȂ�̂ŁA0���Ƃ肠�����Ԃ�.
		if (m_Size.X <= 0) return 0;
		// ...�����Ƃ͎v�������@���A�������͈͊O�ɍs���Ă���Ȃ�ꉞ�N�����v.
		convPos.X = FMath::Clamp<int32>( convPos.X, 0, m_Size.X);

		int32 retIdx = 0;
		retIdx  = convPos.Y * m_Size.X;
		retIdx += convPos.X;

		return retIdx;
	};

	/*!
	 @brief  �w�肳�ꂽPosition���t�B�[���h�����ۂ���Ԃ��܂�.
	 @return �t�B�[���h���̈ʒu�ł����True�@����ȊO��False��Ԃ��܂�.
	*/
	bool IsValidPosition( FIntPoint checkPos )
	{
		if( checkPos.X < 0 || checkPos.X >= m_Size.X ) return false;
		if( checkPos.Y < 0 || checkPos.Y >= m_Size.Y ) return false;

		// �����܂ŗ�����㉺���E�ǂ����Ă��͈͓��ɂ����܂��Ă���@�͂�.
		return true;
	}

public:
	FSetBlockDelegate OnBlockSetDelegate; //!< �u���b�N�ݒ莞�@�̃C�x���g public�ł����̂��Ȃ���...

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	/*!
	 @brief �t�B�[���h���������̊e�ӏ��̃u���b�N�C���X�^���X���擾.
	*/
	UBlock* GetBlockOfFieldReset( FIntPoint resetPos );

private:

	TArray<UBlock*> m_HaveBlocks; //!< �t�B�[���h���̃u���b�N�S��

	FIntPoint m_Size; //!< �t�B�[���h�̑傫��
	FIntPoint m_InSize; //!< �t�B�[���h�̑傫��
	FIntPoint m_InFieldPos; //!< �t�B�[���h�̒��g�̍���ʒu�i�����߂�Idx�j

	// �ǂ�㕔�X�y�[�X���T�C�Y��ǉ�.
	const int32 WALL_HORIZON_NUM = 2; // ���E�ɂP����
	const int32 WALL_BOTTOM_NUM = 1;  // �����ɂP��
	const int32 FIELD_TOP_SPACE = 2;  // �㕔�̋󔒕���

};
