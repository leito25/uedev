// Leonardo Quinones - All Right Reserved


#include "Widgets/Widget_PrimaryLayout.h"

UCommonActivatableWidgetContainerBase* UWidget_PrimaryLayout::FindWidgetStackByTag(const FGameplayTag& InTag) const
{
	// Verify that the requested stack was registered before returning it.
	checkf(RegisteredWidgetStackMap.Contains(InTag), TEXT("Can not find the widget stack by the tag %s"), *InTag.ToString());

	return RegisteredWidgetStackMap.FindRef(InTag);//FindRef is a map funtion to retrieve the value of certain key
}

void UWidget_PrimaryLayout::RegisterWidgetStack(UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack)
{
	if (!IsDesignTime())//!IsDesignTime() means play mode
	{
		// Register each stack tag int the stack MAP only once while the widget is running in-game.
		if (!RegisteredWidgetStackMap.Contains(InStackTag))
		{
			RegisteredWidgetStackMap.Add(InStackTag, InStack);
			UE_LOG(LogTemp, Warning, TEXT("Added InStackTag:  %s and InStack: "), *InStackTag.ToString());
			//ebug::Print(TEXT("Widget Stack Registered under the tag ") + InStackTag.ToString());
		}
	}
}
