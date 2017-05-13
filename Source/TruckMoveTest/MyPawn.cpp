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

	FStringAssetReference SequenceName("/Game/NewLevelSequence");
	ULevelSequence* LevelSequence = Cast<ULevelSequence>(SequenceName.TryLoad());
	ULevelSequencePlayer*  LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), LevelSequence, FLevelSequencePlaybackSettings());
	LevelSequencePlayer->Play();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

