// Fill out your copyright notice in the Description page of Project Settings.


#include "Cell.h"
#include "Components/SphereComponent.h"

// Sets default values
ACell::ACell()
{
	/*USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));*/

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		VisualMesh->SetRelativeScale3D(FVector(0.01f, 0.01f, 0.01f));
	}
}

// Called when the game starts or when spawned
void ACell::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACell::setValue(int v,UMaterial* material)
{
	value = v;

	//const FString a = FString::Printf(TEXT("/Game/yangmaterial/0_%i.NewMaterial"), v + 1);
	//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset(TEXT("/Game/yangmaterial/0_%i.NewMaterial"), v + 1);
	//Material'/Game/yangmaterial/0_5.0_5'
	//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset(TEXT("/Game/yangmaterial/0_%i.0_%i"), v + 1, v + 1);
	//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset(TEXT("/Game/yangmaterial/0_5.0_5"));
	//static ConstructorHelpers::FObjectFinder<UMaterial> materialVisualAsset(TEXT("/Game/yangmaterial/0_.NewMaterial"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> textureVisualAsset(TEXT("/Game/yangimage/166384773226240_25.166384773226240_25"));
	//material = materialVisualAsset.Object;
	//material->Settexture//
	//FString str= material->GetPathName();
	//UE_LOG(LogTemp, Warning, TEXT("fdsfd_ %b"), material==NULL);
	VisualMesh->SetMaterial(0, material);
}
