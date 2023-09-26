// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawns.h"
#include "Zombie.h"


// Sets default values
ASpawns::ASpawns()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	tiempoTranscurrido = 0.0;
	posicion = 0.0;
}

// Called when the game starts or when spawned
void ASpawns::BeginPlay()
{
	Super::BeginPlay();


	


	/*/---------------------------------------------------*/
	for (int32 i = 0; i < 15; i++)
	{
		
		// Instancia la planta
		APlant* NewPlant = GetWorld()->SpawnActor<APlant>(APlant::StaticClass(), FVector(i*100, 0, 100), FRotator::ZeroRotator);

		// Agrega la planta al TMap
		PlantMap.Add(i, NewPlant);
	}


	
}





// Called every frame
void ASpawns::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//DestroyPlant(5);
	tiempoTranscurrido += DeltaTime;
	if (tiempoTranscurrido > 2.0)
	{
		if (posicion < 15)
		{
			DestroyPlant(posicion);
			posicion++;
		}
		tiempoTranscurrido = 0;
	}
}


void ASpawns::DestroyPlant(int32 PlantIndex)
{
	if (PlantMap.Contains(PlantIndex))
	{
		APlant* PlantToRemove = PlantMap[PlantIndex];
		PlantMap.Remove(PlantIndex);
		if (PlantToRemove)
		{
			PlantToRemove->Destroy();
		}
	}
}