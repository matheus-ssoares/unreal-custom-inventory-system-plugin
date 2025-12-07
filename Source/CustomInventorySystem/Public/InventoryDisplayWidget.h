#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryComponent.h"
#include "InventoryDisplayWidget.generated.h"

UCLASS()
class CUSTOMINVENTORYSYSTEM_API UInventoryDisplayWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory UI")
	void InitializeInventory(UInventoryComponent* NewInventory);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Inventory UI")
	UInventoryComponent* LinkedInventory;

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory UI")
	void RefreshWindow();

private:
	UFUNCTION()
	void OnInventoryDataChanged();
};