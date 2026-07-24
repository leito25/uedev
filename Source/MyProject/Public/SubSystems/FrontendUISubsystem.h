// Leonardo Quinones - All Right Reserved
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FrontendUISubsystem.generated.h"

class UWidget_PrimaryLayout;
struct FGameplayTag;
class UWidget_ActivatableBase;

enum class EAsyncPushWidgetState : uint8
{
	OnCreateBeforePush,
	AfterPush
};


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
	
	
private:
	UPROPERTY(Transient)
	UWidget_PrimaryLayout* CreatedPrimaryLayout;//Pointer to the Primary Layout
};
