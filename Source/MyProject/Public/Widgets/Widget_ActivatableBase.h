// Leonardo Quinones - All Right Reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Widget_ActivatableBase.generated.h"

class UCommonActivatableWidgetContainingBase;
class AFrontendPlayerController;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class MYPROJECT_API UWidget_ActivatableBase : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
	// U Function to get the Front end player controller by default
protected:
	UFUNCTION(BlueprintPure)
	AFrontendPlayerController* GetOwningFrontendPlayerController();
	
	//This is a code reference to use the FrontEndController as default
private:
	// object weak ref
	TWeakObjectPtr<AFrontendPlayerController> CachingFrontendOwningPlayerController;
};
