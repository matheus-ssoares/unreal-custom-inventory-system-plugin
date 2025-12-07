#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemData.h"
#include "InventorySlotWidget.generated.h"

UCLASS()
class CUSTOMINVENTORYSYSTEM_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory UI")
	void UpdateSlot(UItemData* Item, int32 Quantity)
	{
		BP_OnUpdateSlot(Item, Quantity);
	}

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory UI")
	void BP_OnUpdateSlot(UItemData* Item, int32 Quantity);
};