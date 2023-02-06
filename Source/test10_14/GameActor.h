// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Cell.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameActor.generated.h"

UCLASS()
class TEST10_14_API AGameActor : public AActor
{
	GENERATED_BODY()
	
public:	
	int texturesLen=5;
	UMaterial* textures[5];
	//ACell* cubePrefabs[];
	int numLayers = 20;
	int numRows = 10;
	int numCols = 10;
	//ACell* data[20][10][10];//layer,x,y
	TArray<ACell*> data;//layer,x,y
	int count;
	//public Transform bar;
	bool fail = false;

<<<<<<< HEAD
	TArray<ACell*> cellsOnBar;
=======
	//List<Cell> cellsOnBar;
>>>>>>> parent of 72904e7 (2)
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
	virtual bool downExistBox(int layer, int row, int col);
	UFUNCTION()
	virtual void OnClick(ACell* cell);
	virtual void updateAllCell();
	virtual void addCellToBar(ACell* cell);
<<<<<<< HEAD
	virtual void updateCell(int layer, int row, int col);
	virtual void setData(int layer, int row, int col,ACell* cell);
	virtual ACell* getData(int layer, int row, int col);
=======
>>>>>>> parent of 72904e7 (2)

};
