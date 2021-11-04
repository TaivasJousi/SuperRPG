// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HitPoints = 100.f;
	DebuffDefence = 1.f;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABaseCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	//damage calculation
	float CalculatedDamage = DamageAmount * DebuffDefence;
	float NewHitPoints = FMath::Clamp(HitPoints - CalculatedDamage, 0.f, HitPoints);

	//calculation of the amount of damage actually aplied
	float ActualDamage = HitPoints - NewHitPoints;

	//Apply damage
	HitPoints = NewHitPoints;

	OnTakeDamage(HitPoints);

	return ActualDamage;
}

void ABaseCharacter::Heal(float Value)
{
	HitPoints = FMath::Clamp(HitPoints + Value, 0.f, HitPoints);
}

void ABaseCharacter::GoToShelter()
{
	OnShelter.Broadcast(100.f);
}

/* void ABaseCharacter::Attack(ABaseCharacter* Target)
{
	Target->TakeDamage(AttackDamage);
}*/