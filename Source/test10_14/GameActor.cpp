// Fill out your copyright notice in the Description page of Project Settings.


#include "GameActor.h"
#include "Cell.h"

// Sets default values
AGameActor::AGameActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//for (int i = 0;i < texturesLen;i++) {
		//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset(TEXT("/Game/yangmaterial/0_%s.0_%s"), i + 1);
		//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset(TEXT("/Game/yangmaterial/0_3.0_3"));
		//textures[i] = materialVisualAsset.Object;

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("fdsfd%s"), materialVisualAsset.Succeeded()));
	//}

	static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset1(TEXT("/Game/yangmaterial/0_1.0_1"));
	textures[0] = materialVisualAsset1.Object;
	static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset2(TEXT("/Game/yangmaterial/0_2.0_2"));
	textures[1] = materialVisualAsset2.Object;
	static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset3(TEXT("/Game/yangmaterial/0_3.0_3"));
	textures[2] = materialVisualAsset3.Object;
	static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset4(TEXT("/Game/yangmaterial/0_4.0_4"));
	textures[3] = materialVisualAsset4.Object;
	static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset5(TEXT("/Game/yangmaterial/0_5.0_5"));
	textures[4] = materialVisualAsset5.Object;
	
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


					//var cube = Instantiate(cubePrefabs[0].gameObject, new Vector3(((float)k - numCols / 2) * size, i * sizeL, ((float)j - numRows / 2) * size), Quaternion.identity, gameObject.transform);
					count++;
					ACell* cell= GetWorld()->SpawnActor<ACell>(SpawnLocation, SpawnRotation);
					//var cell = cube.GetComponent<Cell>();
					int v = FMath::FRandRange(0, texturesLen);
					//cell.texture = textures[v];
					cell->setValue( v,textures[v]);

					//cell->layer = i;
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

