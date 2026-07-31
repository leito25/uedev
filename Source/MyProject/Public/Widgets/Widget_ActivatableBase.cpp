// Leonardo Quinones - All Right Reserved


#include "Widgets/Widget_ActivatableBase.h"
#include "Controllers/FrontendPlayerController.h"

AFrontendPlayerController* UWidget_ActivatableBase::GetOwningFrontendPlayerController()
{
	if (!CachingFrontendOwningPlayerController.IsValid())
	{
		//CachingFrontendOwningPlayerController = GetOwningFrontendPlayerController();
		CachingFrontendOwningPlayerController = GetOwningPlayer<AFrontendPlayerController>();
	}
	
	return CachingFrontendOwningPlayerController.IsValid()? CachingFrontendOwningPlayerController.Get() : nullptr;
}
