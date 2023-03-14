// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "SlashCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;

UCLASS()
class SLASH_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASlashCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Input")
		UInputMappingContext* SlashContext;

	UPROPERTY(EditAnywhere, Category = "Input")
		UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = "Input")
		UInputAction* TurningAction;

	UPROPERTY(EditAnywhere, Category = "Input")
		UInputAction* JumpAction;

	void Move(const FInputActionValue& Value);
	void Turning(const FInputActionValue& Value);
	void virtual Jump() override;

private:
	UPROPERTY(EditAnywhere)
		USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere)
		UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* HairMesh;

	/*UPROPERTY(EditAnywhere, Category = "Hair")
		UGroomComponent* Hair;*/

};
