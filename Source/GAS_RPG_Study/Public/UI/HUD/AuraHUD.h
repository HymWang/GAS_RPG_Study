// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UAuraUserWidget;
/**
 * 
 */
UCLASS()
class GAS_RPG_STUDY_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	/**
	 * 类似单例模式的获取函数，如果OverlayWidgetController存在直接返回，为空则创建一个。
	 * @param WCParams 初始化WidgetController的结构体
	 * @return 返回UOverlayWidgetController
	 */
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	/**
	 * 初始化OverlayUI，设置此UI的Controller类，并将此UI添加到玩家视口，调用此函数时，必须确保参数的类初始化完毕，推荐在InitAbilityActorInfo函数中调用，
	 * 因为玩家初始化时，InitAbilityActorInfo调用时参数一定初始化完成。
	 * @param PC 玩家控制器，APlayerController
	 * @param PS 玩家数据，APlayerState
	 * @param ASC GAS中的ASC组件，UAbilitySystemComponent
	 * @param AS GAS的参数集，UAttributeSet
	 */
	void InitOverlay(APlayerController* PC,APlayerState* PS, UAbilitySystemComponent* ASC,UAttributeSet* AS);

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
};
