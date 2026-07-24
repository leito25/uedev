// Leonardo Quinones All Rights Reserved


#include "AsyncActions/AsyncAction_PushSoftWidget.h"
#include "SubSystems/FrontendUISubsystem.h"
#include "Widgets/Widget_ActivatableBase.h"

UAsyncAction_PushSoftWidget* UAsyncAction_PushSoftWidget::PushSoftWidget(const UObject* WorldContextObject,
	APlayerController* OwningPlayerController, TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass,
	UPARAM(meta = (Categories = "Frontend.WidgetStack")) FGameplayTag InWidgetStackTag, bool bFocusOnNewlyPushedWidget)
{
	checkf(!InSoftWidgetClass.IsNull(), TEXT("PushSoftWidgetToStack was passed a null soft widget class"));
	//checkf(!InWidgetStackTag.IsValid(), TEXT("WidgetStackTag not valid"));

	
	if (GEngine)// Check in runtime
	{
		// 
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			UAsyncAction_PushSoftWidget* Node = NewObject<UAsyncAction_PushSoftWidget>();
			Node->CachedOwningWorld = World;
			Node->CachedOwningPC = OwningPlayerController;
			Node->CachedSoftWidgetClass = InSoftWidgetClass;
			Node->CachedWidgetStackTag = InWidgetStackTag;
			Node->bCachedFocusOnNewlyPushedWidget = bFocusOnNewlyPushedWidget;
			
			Node->RegisterWithGameInstance(World);
			
			return Node;
		}
	}
	
	return nullptr;
}

UAsyncAction_PushSoftWidget* UAsyncAction_PushSoftWidget::MyTestPushSoftWidget()
{
	//Action
	
	return NewObject<UAsyncAction_PushSoftWidget>();
}

void UAsyncAction_PushSoftWidget::Activate()
{
	UFrontendUISubsystem* FrontendUISubsystem = UFrontendUISubsystem::Get(CachedOwningWorld.Get());
	
	FrontendUISubsystem->PushSoftWidgetToStackAsync(CachedWidgetStackTag, CachedSoftWidgetClass,
		[this](EAsyncPushWidgetState InPushState, UWidget_ActivatableBase* PushedWidget)
		{
			switch(InPushState)
			{
			case EAsyncPushWidgetState::OnCreateBeforePush:
				PushedWidget->SetOwningPlayer(CachedOwningPC.Get());
				OnWidgetCreatedBeforePush.Broadcast(PushedWidget);
				break;
			case EAsyncPushWidgetState::AfterPush:
				AfterPush.Broadcast(PushedWidget);
				
				if(bCachedFocusOnNewlyPushedWidget)
				{
					if (UWidget* WidgetToFocus = PushedWidget->GetDesiredFocusTarget())
					{
						WidgetToFocus->SetFocus();
					}
				}
				
				SetReadyToDestroy();
				
				break;
			default:
				break;
			}
		}
	);
}
