// Fill out your copyright notice in the Description page of Project Settings.
//¿ØÖÆÉãÏñ»úÇÐ»»

#include "MyActorCam.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyActorCam::AMyActorCam()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorCam::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorCam::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timetochanged -= DeltaTime;
	if (timetochanged<0) {
		timetochanged +=3;
		APlayerController* ctrl = UGameplayStatics::GetPlayerController(this, 0);
		if (ctrl) {
			if (ctrl->GetViewTarget()!=cam0) {
				ctrl->SetViewTarget(cam0);
			}
			else {
				ctrl->SetViewTargetWithBlend(cam1, 1);
			}
		}
	}

}

