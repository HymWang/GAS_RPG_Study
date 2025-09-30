// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "Controller/AuraPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"

AAuraCharacter::AAuraCharacter()
{
	//让角色的面向，旋转到施加移动（加速）的方向
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//角色的旋转速率
	GetCharacterMovement()->RotationRate = FRotator(0,400,0);
	//关闭使用controller的旋转
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	//限制角色在平面移动
	GetCharacterMovement()->bConstrainToPlane = true;
	//开始时限制在平面
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	//控制器不要控制角色的旋转
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraState = GetPlayerState<AAuraPlayerState>();
	check(AuraState);
	
	AuraState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraState,this);
	
	AbilitySystemComponent = AuraState->GetAbilitySystemComponent();
	AttributeSet = AuraState->GetAttributeSet();

	//在玩家视口中添加OverlayUI（初始化UI并设置UI的Controller类）
	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController,AuraState,AbilitySystemComponent,AttributeSet);
		}
	}
}
