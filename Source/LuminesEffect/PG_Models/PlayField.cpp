// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayField.h"
#include "Blocks/WallBlock.h"
#include "Blocks/SpaceBlock.h"
#include "Blocks/NormalBlock.h"

// Sets default values
APlayField::APlayField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Size = FIntPoint();
	m_InSize = FIntPoint();

	OnBlockSetDelegate = FSetBlockDelegate();
}

// Called when the game starts or when spawned
void APlayField::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayField::Initialize( FIntPoint makeInSize )
{
	m_InSize = makeInSize;
	m_Size = makeInSize;

	// Sizeの方は、壁や上部スペースも含んだサイズになる.
	m_Size.X += WALL_HORIZON_NUM;
	m_Size.Y += WALL_BOTTOM_NUM;
	m_Size.Y += FIELD_TOP_SPACE;

	Reset();
}

// Called every frame
void APlayField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayField::Reset()
{
	m_HaveBlocks.Empty();
	m_HaveBlocks.SetNum(m_Size.X * m_Size.Y);

	for (int32 i = 0; i < m_HaveBlocks.Num(); ++i)
	{
		FIntPoint fieldPos = ConvertIndexToFieldPosition( i );
		SetBlock(GetBlockOfFieldReset( fieldPos ), i);
	}
}

void APlayField::SetBlock(UBlock* block, int32 setIdx)
{
	if( setIdx < 0 || setIdx >= m_HaveBlocks.Num() ) return;

	// 未使用になったブロックを消す.
	// HACK: ...と思ったけど、片付けまでFieldで面倒見るかい...？
	if( m_HaveBlocks[setIdx] != nullptr ) m_HaveBlocks[setIdx]->MarkAsGarbage();

	// 新たなブロックを保持.
	m_HaveBlocks[setIdx] = block;

	if( OnBlockSetDelegate.IsBound() ) OnBlockSetDelegate.Execute( block, setIdx );
}

UBlock* APlayField::GetBlock(int32 getIdx)
{
	if (getIdx < 0 || getIdx >= m_HaveBlocks.Num()) return nullptr;

	return m_HaveBlocks[getIdx];
}

UBlock* APlayField::GetBlockOfFieldReset( FIntPoint resetPos )
{
	bool isWall = false;

	// 左右の壁？
	if (resetPos.X <= 0 || resetPos.X >= (m_Size.X - 1)) isWall = true;
	// 一番下の壁？
	if (resetPos.Y >= (m_Size.Y - 1))                    isWall = true;

	UBlock* retBlock = nullptr;

	if (isWall)
	{
		retBlock = NewObject< UWallBlock >();
	}
	else
	{
		//retBlock = NewObject< USpaceBlock >();

		//でばばば.　NormalBlockも正常に出るか見たいので.
		int32 rand = FMath::RandRange(0,30000);

		switch ( rand % 3 )
		{
			case 0:
				retBlock = NewObject< USpaceBlock >();
				break;
			case 1:
				retBlock = NewObject< UNormalBlock >();
				retBlock->SetHaveColor( EHaveColor::HAVE_COLOR_A );
				break;
			case 2:
				retBlock = NewObject< UNormalBlock >();
				retBlock->SetHaveColor( EHaveColor::HAVE_COLOR_B );
				break;
		}
	}

	return retBlock;
}

