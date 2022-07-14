// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include <GameFramework/CharacterMovementComponent.h>

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
      SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");//创建一个弹簧臂
	  SpringArmComp->SetupAttachment(RootComponent);//把弹簧臂绑定在根组件上
	  SpringArmComp->bUsePawnControlRotation = true;//用到弹簧臂的旋转
	  CamComp = CreateDefaultSubobject<UCameraComponent>("CamComp");
	  CamComp->SetupAttachment(SpringArmComp);//把摄像机绑定在弹簧臂上
	  GetCharacterMovement()->bOrientRotationToMovement = true;//运动体朝向的旋转
	  bUseControllerRotationYaw = false;
}

void ASCharacter::MoveForward(float value)
{
	FRotator ControlRol = GetControlRotation();
	ControlRol.Pitch = 0.0f;//除了围绕Z轴旋转，其余的旋转量都为0
	ControlRol.Roll = 0.0f;
	AddMovementInput(ControlRol.Vector(), value);
}

void ASCharacter::MoveRight(float value)
{
	FRotator ControlRol = GetControlRotation();
	ControlRol.Pitch = 0.0f;//除了围绕Z轴旋转，其余的旋转量都为0
	ControlRol.Roll = 0.0f;
	//x=Forward(Red)
	//y=Right(green)
	//z=Up(Blue)
	FVector RightVector = FRotationMatrix(ControlRol).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVector, value);
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
	PlayerInputComponent->BindAxis("MoveForward", this,&ASCharacter::MoveForward);//绑定键盘W，向前移动事件
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);//绑定键盘D，向左移动
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);//鼠标X轴控制旋转
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);//鼠标Y轴控制Y轴旋转
} 

