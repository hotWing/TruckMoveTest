// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class TRUCKMOVETEST_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category=Custom)
		void setTruck(AActor* t);

	UFUNCTION(BlueprintCallable, Category = Custom)
		void setWall(AActor* wall);

	UPROPERTY(EditAnyWhere, Category = Custom)
		TArray<UTexture2D*> textures;

protected:

		AActor* truck;
		AActor* wall;

private:
	int texIndex;
	void NextTex();
	void PreTex();
	void setTex(UTexture2D* tex);
};
