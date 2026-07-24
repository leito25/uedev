// Leonardo Quinones - All Right Reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Widget_ActivatableBase.generated.h"

class UCommonActivatableWidgetContainingBase;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class MYPROJECT_API UWidget_ActivatableBase : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
};
