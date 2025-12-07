#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UInventoryComponent::AddItem(UItemData* Item, int32 Quantity)
{
	if (!Item || Quantity <= 0) return false;

	// 1. Check for existing stack
	int32 SlotIndex = FindSlot(Item);
	if (SlotIndex >= 0)
	{
		Content[SlotIndex].Quantity += Quantity;
		OnInventoryUpdated.Broadcast();
		return true;
	}

	// 2. Add new slot if space exists
	if (Content.Num() < MaxSlots)
	{
		FInventorySlot NewSlot;
		NewSlot.ItemData = Item;
		NewSlot.Quantity = Quantity;
		Content.Add(NewSlot);
		OnInventoryUpdated.Broadcast();
		return true;
	}

	return false;
}

int32 UInventoryComponent::FindSlot(UItemData* Item)
{
	for (int32 i = 0; i < Content.Num(); i++)
	{
		if (Content[i].ItemData == Item && Content[i].Quantity < Item->MaxStackSize)
		{
			return i;
		}
	}
	return -1;
}