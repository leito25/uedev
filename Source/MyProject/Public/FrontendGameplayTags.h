// Leonardo Quinones - All Right Reserved
#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace FrontendGameplayTags
{
	//
	// Frontend widget stack
	MYPROJECT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_WidgetStack_Modal);
	MYPROJECT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_WidgetStack_GameMenu);
	MYPROJECT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_WidgetStack_GameHud);
	MYPROJECT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_WidgetStack_Frontend);
	
	// Frontend widgets
	MYPROJECT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_Widget_PressAnyKeyScreen);
	MYPROJECT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Frontend_Widget_MainMenuScreen);
}