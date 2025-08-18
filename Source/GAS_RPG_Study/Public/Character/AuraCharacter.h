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
	void InitAbilityActorInfo();
};
