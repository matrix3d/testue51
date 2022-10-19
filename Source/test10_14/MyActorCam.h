// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorCam.generated.h"

UCLASS()
class TEST10_14_API AMyActorCam : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere)
		AActor* cam0;

	UPROPERTY(EditAnywhere)
		AActor* cam1;
	float timetochanged=-1.0;
	AMyActorCam();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
