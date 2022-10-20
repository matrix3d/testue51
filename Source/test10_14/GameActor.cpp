// Fill out your copyright notice in the Description page of Project Settings.


#include "GameActor.h"
#include "Cell.h"

// Sets default values
AGameActor::AGameActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// cpp文件中定义函数
void AGameActor::ReStart()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("ReStart")));
	/*FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();

	GetWorld()->SpawnActor<ACell>(SpawnLocation, SpawnRotation);*/


	count = 0;
	fail = false;
	/*if (cellsOnBar != null)
	foreach(Cell cell in cellsOnBar)
	{
		cell.transform.DOKill();
		Destroy(cell.gameObject);
	}

	cellsOnBar = new List<Cell>();
	if (data != null)
	{
		for (var i = 0; i < numLayers; i++)
		{
			for (var j = 0; j < numRows; j++)
			{
				for (var k = 0; k < numCols; k++)
				{
					var cell = data[i, j, k];
					if (cell != null)
					{
						cell.transform.DOKill();
						Destroy(cell.gameObject);
					}
				}
			}
		}
	}
	data = new Cell[numLayers, numRows, numCols];*/
	for (int i = 0; i < numLayers; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			for (int k = 0; k < numCols; k++)
			{
				if (FMath::SRand() < 0.5f && i % 2 == j % 2 && i % 2 == k % 2/* && downExistBox(i, j, k)*/)
				{
					int size = 1;
					float sizeL = 1.0f;

					FVector SpawnLocation = FVector(((float)k - numCols / 2) * size, i * sizeL, ((float)j - numRows / 2) * size);
					FRotator SpawnRotation = GetActorRotation();

					GetWorld()->SpawnActor<ACell>(SpawnLocation, SpawnRotation);

					//var cube = Instantiate(cubePrefabs[0].gameObject, new Vector3(((float)k - numCols / 2) * size, i * sizeL, ((float)j - numRows / 2) * size), Quaternion.identity, gameObject.transform);
					count++;
					//var cell = cube.GetComponent<Cell>();
					//var v = Random.Range(0, textures.Length);
					//cell.texture = textures[v];
					//cell.Value = v;

					//cell.layer = i;
					//cell.row = j;
					//cell.col = k;
					//cell.OnClick.AddListener(() = > {
					//	if (fail)
					//	{
					//		return;
					//	}

					//	OneShotAudio.playOneShot("166384774385063");
					//	print("onclick" + cell.layer + "," + cell.row + "," + cell.col);
					//	data[cell.layer, cell.row, cell.col] = null;
					//	updateAllCell();
					//	addCellToBar(cell);

					//	count--;
					//	if (count <= 0 && !fail)
					//	{
					//		//print("通关");
					//		//ui.Show(true, false);
					//	}
					//});
					//data[i, j, k] = cell;
				}

			}
		}
	}
	//updateAllCell();
}

// Called every frame
void AGameActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

