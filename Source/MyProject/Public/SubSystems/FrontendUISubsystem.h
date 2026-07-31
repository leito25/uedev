// Leonardo Quinones - All Right Reserved
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/Texture2D.h"
#include "FrontendUISubsystem.generated.h"

class UWidget_PrimaryLayout;
struct FGameplayTag;
class UWidget_ActivatableBase;
class UFrontendCommonButtonBase;

class UFrontendUISubsystem;

enum class EAsyncPushWidgetState : uint8
{
	OnCreateBeforePush,
	AfterPush
};

//Events
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnButtonDescriptionTextUpdateDelegate, UFrontendCommonButtonBase*, BroadcastingButton, FText, DescriptionText, bool, OnOff);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnButtonBtnBackgroundUpdateDelegate, UFrontendCommonButtonBase*, BroadcastingButton, bool, ONOFF);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnButtonBtnBackgroundUpdateDelegate, UFrontendCommonButtonBase*, BroadcastingButton, UTexture2D*, BackgroundTexture);


/**
 * 
 */
UCLASS()
class MYPROJECT_API UFrontendUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	// Getter, the getter is applied to the Wor3ld Context Object
	static UFrontendUISubsystem* Get(const UObject* WorldContextObject);
	
	//~ Begin USubsystem Interface
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	//~ End USubsystem Interface
	
	
	
	//variable to hold the primary layout
	UFUNCTION(BlueprintCallable)
	void RegisterCreatedPrimaryLayoutWidget(UWidget_PrimaryLayout* InCreatedWidget);
	
	void PushSoftWidgetToStackAsync(const FGameplayTag& InWidgetStackTag, 
		TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass,
		TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)> AsyncPushStateCallback
		);
	
	
	
	// UPRoperty BP for apply and link the description text
	UPROPERTY(BlueprintAssignable)
	FOnButtonDescriptionTextUpdateDelegate OnButtonDescriptionTextUpdated;
	
private:
	UPROPERTY(Transient)
	UWidget_PrimaryLayout* CreatedPrimaryLayout;//Pointer to the Primary Layout
};
