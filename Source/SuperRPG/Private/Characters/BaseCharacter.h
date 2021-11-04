// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShelterDelegate, float, Height);

UCLASS()
class ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Main|Characteristics");
	float DebuffDefence;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Main|Characteristics");
	float HitPoints;//general hp

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable, EditAnywhere, Category = "Main|Behaviour");
	FShelterDelegate OnShelter;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Main|Characteristics");
	//float AttackDamage;//damage points to the enemy

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter|Damage")
		virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;//receive damage

	UFUNCTION(BlueprintCallable, Category = "Main|Behaviour")
		void GoToShelter();

	UFUNCTION(BlueprintCallable, Category = "BaseCharacter|Heal")
		void Heal(float Value);//restore health

		//implemented in Blueprint
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "BaseCharacter|Damage")
		void OnTakeDamage(float TotalHitPoints);

	//UFUNCTION(BlueprintCallable, Category = "BaseCharacter|Damage")
	//void Attack(ABaseCharacter* Target);

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};