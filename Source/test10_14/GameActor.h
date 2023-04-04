// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Cell.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FONAddCellToBar);
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPFunc_Lib")
	TArray<ACell*> cellsOnBar;

	UPROPERTY(BlueprintAssignable)
	FONAddCellToBar onaddCellToBar;
	//public GameUI ui;

	// Sets default values for this actor's properties
	AGameActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintCallable, Category = "BPFunc_Lib")
		virtual	void ReStart();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual bool downExistBox(int layer, int row, int col);
	UFUNCTION(BlueprintCallable, Category = "BPFunc_Lib")
	virtual void OnClick(ACell* cell);
	virtual void updateAllCell();
	//UFUNCTION(BlueprintImplementableEvent, Category = "BPFunc_Lib")
	virtual void addCellToBar(ACell* cell);
	virtual void updateCell(int layer, int row, int col);
	virtual void setData(int layer, int row, int col,ACell* cell);
	virtual ACell* getData(int layer, int row, int col);
	//UPROPERTY(Category = "BPFunc_Lib")
	UFUNCTION(BlueprintPure, Category = "BPFunc_Lib")
	virtual	ACell* GetMycellsOnBar(int i);
};
