// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainHero.h"

// Sets default values
AMainHero::AMainHero()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//HitPoints = 100.f;
	//AttackDamage = 20.f;

}

// Called when the game starts or when spawned
void AMainHero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

