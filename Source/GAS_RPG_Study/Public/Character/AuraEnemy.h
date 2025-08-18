// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/GASCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class GAS_RPG_STUDY_API AAuraEnemy : public AGASCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	/** EnemyInterface */
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
	/** End EnemyInterface*/

protected:
	virtual void BeginPlay() override;
};
