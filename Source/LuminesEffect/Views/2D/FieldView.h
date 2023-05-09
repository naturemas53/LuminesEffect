// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../../PG_Models/PlayField.h"
#include "Blocks/BlockView.h"
#include "FieldView.generated.h"

class UBlock;
/**
 * 
 */
UCLASS()
class LUMINESEFFECT_API UFieldView : public UUserWidget
{
	GENERATED_BODY()

public:

	/*!
	 @brief ����������.
	 @param[in] initializedField �Q�ƌ���Field�i���������A�������ς݁i���T�C�Y�ݒ�ς݁j�Ƃ��܂��I�j
	*/
	UFUNCTION(BlueprintCallable)
	void InitializeView( APlayField* initializedField );

	/*!
	 @brief �Q�ƒ��̃t�B�[���h �̃T�C�Y��Ԃ��֐�.
	*/
	UFUNCTION(BlueprintPure)
	FIntPoint GetRefFieldSize()
	{
		if( m_RefField == nullptr ) return FIntPoint();

		return m_RefField->GetSize();
	}

private:
	
	/*!
	 @brief �t�B�[���h���̃u���b�N�ύX���ɑΉ����āAView��ύX�����鏈��.
	*/
	void SwapViewOfDataChanged( UBlock* changedBlock, int32 swapIdx );

	/*!
	 @brief �u���b�N�ύX���Ŏg�p���Ȃ��Ȃ�View���\���ɂ��ĕێ����܂�.
	*/
	void RecycleBlockView( int32 recycleIdx );

	/*!
	 @brief �w��ӏ��̃u���b�NView��ύX���܂�.
	*/
	void DispNewestBlockView(UBlock* dispBlock, int32 dispIdx);


public:
	/*!
		@brief �u���b�N�ύX���Ŏg�p���Ȃ��Ȃ�View���\���ɂ��ĕێ����܂�.
			   ...���A���̎���BP���̏����ł�.�iCanvas����̃f�^�b�`�Ƃ��j.
	*/
	UFUNCTION(BlueprintImplementableEvent)
		void RecycleBlockView_BPImpl(UBlockView* recycleView);
	/*!
		@brief �w��ӏ��̃u���b�NView��ύX...�@����ۂ́ABP���̏����ł��iCanvas�A�^�b�`�Ƃ��H�j.
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void DispNewestBlockView_BPImpl(UBlockView* blockView, FIntPoint fieldPos);

private:
	APlayField* m_RefField = nullptr; //!< �Q�Ɛ�̃t�B�[���h.

	TArray< UBlockView* > m_haveBlockViews; //!< ��View���\�����Ă���BlockView�̏W�܂�.
	TMap< EBlockType, TArray<UBlockView*> > m_UnUsedBlockViews; //!< ���g�p�̃u���b�NView HACK:...���ꑽ�����N���X����Ȃ�������

protected:
	UPROPERTY(BlueprintReadWrite)
	TMap< EBlockType, TSoftClassPtr<UBlockView> > m_ViewSoftClassies; //!< �e�u���b�N��View�̌��т�.
};
