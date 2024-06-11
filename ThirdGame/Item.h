
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"
class UCapsuleComponent; 
class USphereComponent;
class UBoxComponent;

UCLASS()
class THIRDGAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;
	
	//virtual void NotifyActorOverlapEnd(AActor* Other, UPrimitiveComponent* OtherComp, int32 UserIndex) override;
	UFUNCTION()
	virtual void OnSphereOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
	UFUNCTION()
	virtual void OnSphereEndOverlap(class UPrimitiveComponent* OnComponentEndOverlap, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32  OtherBodyIndex);
protected:
	virtual void BeginPlay() override;

	//UFUNCTION()
	//void NotifyActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//UFUNCTION()
	//void OnSphereEndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;
private:
	

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* MyBoxComponent;
};
