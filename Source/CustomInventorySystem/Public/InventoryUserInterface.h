#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemData.h" // Required to recognize UItemData*
#include "InventoryUserInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UInventoryUserInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for any Actor (Player, Chest, Vehicle) that can "Use" an inventory item.
 */
class CUSTOMINVENTORYSYSTEM_API IInventoryUserInterface
{
	GENERATED_BODY()

public:
	/** * Event triggered when an inventory item is clicked.
	 * BlueprintNativeEvent allows this to be implemented in C++ (_Implementation) OR Blueprints.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory")
	void RequestUseItem(UItemData* ItemData, int32 ItemIndex);
};