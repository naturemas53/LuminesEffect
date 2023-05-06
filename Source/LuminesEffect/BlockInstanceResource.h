// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockInstanceResource.generated.h"
#include "InGameCommon.h"
#include "Blocks/Block.h"

UCLASS()
class LUMINESEFFECT_API ABlockInstanceResource : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockInstanceResource();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	// virtual void Tick(float DeltaTime) override;

private:
	
	TMap< EBlockType, TArray<UBlock> > m_UnUsedBlocks; //!< 未使用ブロックデータ.
	//TMap< EBlockType, TArray<UBlock> > m_UnUsedBlockView; //!< 未使用ブロックデータ.

};
