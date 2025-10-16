// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature,float,NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature,float,NewMaxHealth);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature,float,NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature,float,NewMaxMana);

/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class GAS_RPG_STUDY_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	//初始化时，调用回调函数设置初始时的UI中的数值
	virtual  void BroadcastInitialValues() override;

	//ASC中自带了数值变化时的回调函数，将WidgetController中的函数绑定到ASC中的回调函数中
	virtual void BindCallBackToDependencies() override;

	UPROPERTY(BlueprintAssignable,Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable,Category = "GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable,Category = "GAS|Attributes")
	FOnManaChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable,Category = "GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;
protected:
	//AS中，Health值变化时的绑定的回调函数
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	//AS中，MaxHealth值变化时的绑定的回调函数
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;

	//AS中，Mana值变化时的绑定的回调函数
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	//AS中，MaxMana值变化时的绑定的回调函数
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
};
