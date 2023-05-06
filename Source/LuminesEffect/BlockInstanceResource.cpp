// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockInstanceResource.h"

// Sets default values
ABlockInstanceResource::ABlockInstanceResource()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// MEMO:ただのブロック管理なので、
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABlockInstanceResource::BeginPlay()
{
	Super::BeginPlay();
	
}

