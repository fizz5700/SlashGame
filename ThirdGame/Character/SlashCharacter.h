
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"
class AItem;
//class ECharacterState;

//UENUM(BlueprintType)
//enum class ECharacterState :uint8
//{
//	ECS_Unequipped UMETA(DisplayName = "Unequipped"),
//	ECS_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped One-Handed Weapon"),
//	ECS_EquippedTwoHandedWeapon UMETA(DisplayName = "Equipped Two-Handed Weapon")
//};
UCLASS()
class THIRDGAME_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void EKeyPressed();

	UPROPERTY(EditAnywhere)
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleInstanceOnly)
	AItem* OverlappingItem;
	//UPROPERTY(EditDefaultsOnly, Category = "Montage")
	//UAnimontage* Attackmontage;

public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) {
		OverlappingItem = Item;
	}
	
	FORCEINLINE ECharacterState GetCharacterState() const{
		return CharacterState;
	}


};
