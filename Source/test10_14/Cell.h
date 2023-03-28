// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cell.generated.h"

UCLASS()
class TEST10_14_API ACell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
		UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;
		 int layer;
		 int row;
		 int col;
		int value;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BPFunc_Lib")
		UMaterial* mymaterial;

	ACell();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void setValue(int value,UMaterial* material);
	UFUNCTION(BlueprintPure, Category = "BPFunc_Lib")
	virtual	UTexture2D* GetTextureFromMaterial();

};
