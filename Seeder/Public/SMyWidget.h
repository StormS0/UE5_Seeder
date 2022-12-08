// Copyright Seeder, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SUserWidget.h"

#include "SocketObject.h"
class SMyWidget : public SUserWidget
{
public:
	SLATE_USER_ARGS(SMyWidget)
	{}
	SLATE_END_ARGS()

		// MUST Provide this function for SNew to call!
	virtual void Construct(const FArguments& InArgs);
	
	//virtual void DoSomething() = 0;
private:
	TSharedPtr<class STextBlock> ipSTextBlock;
	TSharedPtr<class SEditableTextBox> IPEditableText;
	TSharedPtr<class SEditableTextBox> msgEditableTextBox;
	TSharedPtr<class SSlider> Slider;
	
	
	TArray<TSharedPtr<class SCheckBox>> CheckBoxs;

	TSharedPtr<class STextBlock> ComboText;

	TArray<TSharedPtr<FString>> Options;
	
	USocketObject* MySocketObject;
};