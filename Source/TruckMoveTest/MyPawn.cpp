// Fill out your copyright notice in the Description page of Project Settings.

#include "TruckMoveTest.h"
#include "MyPawn.h"
#include "LevelSequence.h"
#include "LevelSequencePlayer.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	texIndex = 0;
	/*FStringAssetReference SequenceName("/Game/NewLevelSequence");
	ULevelSequence* LevelSequence = Cast<ULevelSequence>(SequenceName.TryLoad());
	ULevelSequencePlayer*  LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), LevelSequence, FLevelSequencePlaybackSettings());
	LevelSequencePlayer->Play();*/
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//if (nullptr != truck)
	//{
	//	this->SetActorLocation(truck->GetActorLocation());
	//}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	
	InputComponent->BindAction("Right", IE_Pressed, this, &AMyPawn::NextTex);
	InputComponent->BindAction("Left", IE_Pressed, this, &AMyPawn::PreTex);
}

void AMyPawn::setTruck(AActor* t)
{
	truck = t;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, truck->GetName());
}

void AMyPawn::setWall(AActor* w)
{
	wall = w;
}

void AMyPawn::NextTex()
{
	setTex(textures[++texIndex % 3]);
}

void AMyPawn::PreTex()
{
	if (texIndex == 0)
		texIndex = 2;
	else
		--texIndex;
	setTex(textures[texIndex % 3]);
}

void AMyPawn::setTex(UTexture2D* tex)
{
	UStaticMeshComponent* mat = Cast<UStaticMeshComponent>(wall->GetComponentsByClass(UStaticMeshComponent::StaticClass())[0]);
	mat->CreateAndSetMaterialInstanceDynamic(0)->SetTextureParameterValue(FName("tex"), tex);
}
