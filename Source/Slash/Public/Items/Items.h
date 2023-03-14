// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

class USphereComponent;

UCLASS()
class SLASH_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphrerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		float RunningTime;

	UPROPERTY(EditAnywhere)
		float Amplitude = 0.4f;

	UPROPERTY(EditAnywhere)
		float TimeConstant = 1.0f;

	UFUNCTION(BlueprintCallable)
		float TransformedSin();

	UFUNCTION(BlueprintCallable)
		float TransformedCos();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere)
		USphereComponent* Sphere;
	
};
