// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
      SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");//创建一个弹簧臂
	  SpringArmComp->SetupAttachment(RootComponent);//把弹簧臂绑定在根组件上
	  CamComp = CreateDefaultSubobject<UCameraComponent>("CamComp");
	  CamComp->SetupAttachment(SpringArmComp);//把摄像机绑定在弹簧臂上
}

void ASCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this,&ASCharacter::MoveForward);//绑定键盘W，移动事件
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);//鼠标X轴控制旋转
}

