// Fill out your copyright notice in the Description page of Project Settings.


#include "Zombie.h"

// Sets default values
AZombie::AZombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Cambiando apariencia
	AspectoZombie = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Aspecto Zombie"));
	RootComponent = AspectoZombie;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshZombie1(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	AspectoZombie->SetStaticMesh(MeshZombie1.Object);

	Velocidad = 50.0f;

}

// Called when the game starts or when spawned
void AZombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Animar movimiento hacia x=0
	FVector UbicacionObjetivo = FVector(0.0f, 200.0f, 100.0f);
	FVector Direccion = (UbicacionObjetivo - this->GetActorLocation()).GetSafeNormal();
	float DistanciaObjetivo = FVector::Dist(UbicacionObjetivo, this->GetActorLocation());
	float DeltaMove = Velocidad * GetWorld()->DeltaTimeSeconds;

	if (DeltaMove > DistanciaObjetivo)
	{
		this->SetActorLocation(UbicacionObjetivo); //Actualiza instantaneamente la posicion del zombie a (UbicacionObjetivo)
	}
	else
	{
		this->AddActorWorldOffset(Direccion * DeltaMove); //Suma (Direccion * DeltaMove) a la posicion actual del zombie
	}
}

