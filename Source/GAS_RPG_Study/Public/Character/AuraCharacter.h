// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GASCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAS_RPG_STUDY_API AAuraCharacter : public AGASCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	//服务器端调用
	virtual void PossessedBy(AController* NewController) override;

	//客户端调用
	virtual void OnRep_PlayerState() override;

private:
	/**
	 * 调用玩家PlayerState中的ASC组件的InitAbilityActorInfo函数，并将PlayerState中的ASC组件以及AttributeSet赋值给父类中的ASC及AttributeSet指针。
	 * 调用时必须确保PlayerState以及PlayerController初始化完成。
	 */
	void InitAbilityActorInfo();
};
