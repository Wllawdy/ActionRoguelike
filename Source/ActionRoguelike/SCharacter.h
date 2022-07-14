// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "SCharacter.generated.h"
//class UcameraComponent;
//class UspringArmComponent;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CamComp;//变量在蓝图中暴露出来
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;//变量在蓝图中暴露出来
	void MoveForward(float value);
	void MoveRight(float value);
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
