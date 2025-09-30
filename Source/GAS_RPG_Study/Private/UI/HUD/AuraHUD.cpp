// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (!OverlayWidgetController)
	{
		if (OverlayWidgetControllerClass)
		{
			OverlayWidgetController = NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
			OverlayWidgetController->SetWidgetControllerParams(WCParams);
			return OverlayWidgetController;
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("OverlayWidgetControllerClass is Nullptr! Please Set OverlayWidgetControllerClass."));
		}
	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	//检查类是否在蓝图中设置
	checkf(OverlayWidgetClass,TEXT("OverlayWidgetClass is Nullptr! Please Set OverlayWidgetControllerClass."));
	checkf(OverlayWidgetControllerClass,TEXT("OverlayWidgetControllerClass is Nullptr! Please Set OverlayWidgetControllerClass."));

	//创建Overlay的UI类
	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(),OverlayWidgetClass);

	//初始化此UI的Controller类
	const FWidgetControllerParams WidgetControllerParams(PC,PS,ASC,AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	OverlayWidget->SetWidgetController(WidgetController);

	//初始化完成后的广播事件
	WidgetController->BroadcastInitialValues();
	
	//将UI显示到视口
	OverlayWidget->AddToViewport();
}

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();
	
}
