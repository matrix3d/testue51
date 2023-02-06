// Fill out your copyright notice in the Description page of Project Settings.


#include "GameActor.h"
#include "Cell.h"

// Sets default values
AGameActor::AGameActor()
{
	data.Init(NULL, numRows * numCols * numLayers);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	for (int i = 0;i < texturesLen;i++) {
		//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset(TEXT("/Game/yangmaterial/0_%s.0_%s"), i + 1);
		//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset(TEXT("/Game/yangmaterial/0_3.0_3"));
		//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset1(TEXT("/Game/yangmaterial/0_%d.0_%d"), i+1);
		//textures[0] = materialVisualAsset1.Object;
		//textures[i] = materialVisualAsset1.Object;

		/*static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset1(TEXT("/Game/yangmaterial/0_%d.0_%d"), i+1);
		textures[i] = materialVisualAsset1.Object;*/

	//	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("fdsfd%s"), materialVisualAsset.Succeeded()));
	}
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

bool AGameActor::downExistBox(int layer, int row, int col)
{
	if (layer == 0)
	{
		return true;
	}
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int l = layer - 1;
			int r = row + i;
			int c = col + j;

			
			if (r >= 0 && c >= 0 && r < numRows && c < numCols && getData(l,r,c) != NULL)
			{
				return true;
			}
		}
	}
	return false;
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
				if (FMath::SRand() < 0.5f && i % 2 == j % 2 && i % 2 == k % 2 && downExistBox(i, j, k))
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

					cell->layer = i;
					cell->row = j;
					cell->col = k;

					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("1112")));
					FScriptDelegate onClickFun;
					onClickFun.BindUFunction(this, FName("OnClick"));
					cell->OnClicked.AddUnique(onClickFun);
					setData(i,j,k,cell);
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

void AGameActor::OnClick(ACell* cell) {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("111%d,%d,%d"),cell->row, cell->col,cell->layer));
	UE_LOG(LogTemp,Warning,TEXT("click"));

	if (fail)
	{
		return;
	}

	//	OneShotAudio.playOneShot("166384774385063");
	//	print("onclick" + cell.layer + "," + cell.row + "," + cell.col);
	setData(cell->row,cell->col,cell->layer,NULL);
	updateAllCell();
	addCellToBar(cell);

	count--;
	if (count <= 0 && !fail)
	{
			//print("通关");
			//ui.Show(true, false);
	}
}
void AGameActor::updateAllCell() {
<<<<<<< HEAD
	for (int i = 0; i < numLayers; i++)
	{
		for (int j = 0; j < numRows; j++)
		{
			for (int k = 0; k < numCols; k++)
			{
				ACell* v = getData(i,j,k);
				if (v != NULL)
				{
					updateCell(i, j, k);
				}
			}
		}
	}
}
void AGameActor::addCellToBar(ACell* cell) {
	//cell->Destroy();

	bool added = false;
	FVector loca=FVector(8 * 2 + 1, 0, 0);
	FQuat rot;
	cell->SetActorLocationAndRotation(loca,rot,false);
	/*for (int i = 0; i < cellsOnBar.Count; i++) {
		var c = cellsOnBar[i];
		if (c.Value == cell.Value)
		{
			if (i < cellsOnBar.Count - 1)
			{
				if (cellsOnBar[i + 1].Value == cell.Value)
				{
					var a = cellsOnBar[i].gameObject;
					var b = cellsOnBar[i + 1].gameObject;
					cellsOnBar.RemoveRange(i, 2);
					var ce = cell.gameObject;
					ce.transform.DOLocalMoveX(b.transform.localPosition.x + 2, .5f).onComplete = () = > {
						Destroy(a);
						Destroy(b);
						Destroy(ce);
						OneShotAudio.playOneShot("166384774687269");
					};
				}
				else
				{
					cellsOnBar.Insert(i + 1, cell);
				}
				added = true;
			}
			break;
		}
	}
	if (!added) {
		cellsOnBar.Add(cell);
	}
	cell.transform.SetParent(bar.transform, false);
	cell.mouseEnabled = false;
	cell.setAlpha(false);

	updateCellOnBar();
	if (cellsOnBar.Count >= 7)
	{
		print("Ê§°Ü");
		ui.Show(false, true);
		fail = true;
	}*/
}

void AGameActor::updateCell(int layer, int row, int col) {
	if (layer < 0 || !(row >= 0 && col >= 0 && row < numRows && col < numCols))
	{
		return;
	}

	bool e = true;
	if (layer < numLayers - 1)
	{
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++)
			{
				int l = layer + 1;
				int r = row + i;
				int c = col + j;
				if (r >= 0 && c >= 0 && r < numRows && c < numCols && getData(l,r,c) != NULL)
				{
					e = false; break;
				}
			}
			if (!e)
			{
				break;
			}
		}
	}

	ACell* obj = getData(layer,row,col);
	if (obj != NULL)
	{
		//obj.mouseEnabled = e;
	}
=======
}
void AGameActor::addCellToBar(ACell* cell) {
	cell->Destroy();
>>>>>>> parent of 72904e7 (2)
}

void AGameActor::setData(int layer, int row, int col, ACell* cell) {
	data[layer * numRows * numCols + row * numCols + col] = cell;
}
ACell* AGameActor::getData(int layer, int row, int col) {
	return data[layer * numRows * numCols + row * numCols + col];
}

