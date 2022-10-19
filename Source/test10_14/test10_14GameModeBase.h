// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "test10_14GameModeBase.generated.h"

/**
    *
    */
UCLASS()
class TEST10_14_API Atest10_14GameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    /** �Ƴ���ǰ�˵��ؼ�������ָ���ࣨ���У����½��ؼ���*/
    UFUNCTION(BlueprintCallable, Category = "UMG Game")
        void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
    /** ��Ϸ��ʼʱ���á�*/
    virtual void BeginPlay() override;

    /** ��Ϸ��ʼʱ�������˵��Ŀؼ��ࡣ*/
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
        TSubclassOf<UUserWidget> StartingWidgetClass;

    /** �����˵��Ŀؼ�ʵ����*/
    UPROPERTY()
        UUserWidget* CurrentWidget;
};