// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plant.h"
#include "Spawns.generated.h"



UCLASS()
class PVZ_USFX_LAB01_API ASpawns : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawns();

	// -------------------------
	TMap<int32, APlant*> PlantMap;
	void DestroyPlant(int32 PlantIndex);
	float tiempoTranscurrido;
	float posicion;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
