#include "InventoryDisplayWidget.h"

void UInventoryDisplayWidget::InitializeInventory(UInventoryComponent* NewInventory)
{
	if (LinkedInventory)
	{
		LinkedInventory->OnInventoryUpdated.RemoveDynamic(this, &UInventoryDisplayWidget::OnInventoryDataChanged);
	}

	LinkedInventory = NewInventory;

	if (LinkedInventory)
	{
		LinkedInventory->OnInventoryUpdated.AddDynamic(this, &UInventoryDisplayWidget::OnInventoryDataChanged);
		OnInventoryDataChanged(); // Initial Draw
	}
}

void UInventoryDisplayWidget::OnInventoryDataChanged()
{
	RefreshWindow();
}