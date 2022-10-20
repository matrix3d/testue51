// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameActor.generated.h"

UCLASS()
class TEST10_14_API AGameActor : public AActor
{
	GENERATED_BODY()
	
public:	
	//public Texture[] textures;
	//public Cell[] cubePrefabs;
	int numLayers = 20;
	int numRows = 10;
	int numCols = 10;
	//Cell[, , ] data;//layer,x,y
	int count;
	//public Transform bar;
	bool fail = false;

	//List<Cell> cellsOnBar;
	//public GameUI ui;


	UFUNCTION(BlueprintCallable, Category = "BPFunc_Lib")
		void ReStart();
	// Sets default values for this actor's properties
	AGameActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
