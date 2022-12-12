// Copyright 2022 Seeder, Inc. All Rights Reserved.
#include "SMyWidget.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SGridPanel.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Input/SSlider.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableText.h"
#include "Widgets/Input/SEditableTextBox.h"


//#include "D:\Program Files\Epic Games\UE_5.1\Engine\Source\Runtime\UMG\Public\Components\EditableText.h"

void SMyWidget::Construct(const FArguments& InArgs)
{
	
	int32 BoxId = 0;
	CheckBoxs.SetNum(2);
	if (Options.Num() <= 0) {
		Options.Add(MakeShareable(new FString(TEXT("0"))));
		Options.Add(MakeShareable(new FString(TEXT("1"))));
		Options.Add(MakeShareable(new FString(TEXT("2"))));
	}
	SUserWidget::Construct(
		SUserWidget::FArguments().HAlign(HAlign_Fill).VAlign(VAlign_Fill)
		[
			SNew(SGridPanel)
			.FillColumn(0, 1).FillColumn(1, 3)
		.FillRow(0, 1).FillRow(1, 1).FillRow(2, 1).FillRow(3, 1)
		+ SGridPanel::Slot(0, 0).HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(STextBlock).Text(FText::FromString(TEXT("IP : PORT")))
		]
	+ SGridPanel::Slot(0, 1).HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(STextBlock).Text(FText::FromString(TEXT("Method")))
		]
	+ SGridPanel::Slot(0, 2).HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(STextBlock).Text(FText::FromString(TEXT("MSG")))
		]
	+ SGridPanel::Slot(0, 3).HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SNew(SEditableText)
			


		]
	+ SGridPanel::Slot(1, 0).HAlign(HAlign_Fill).VAlign(VAlign_Center)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().FillWidth(3)
		[
			SAssignNew(IPEditableText, SEditableTextBox)
			.Text(FText::FromString(TEXT("192.168.0.11:8456")))
		]
	+ SHorizontalBox::Slot().FillWidth(1)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateLambda([this]()
				{
					FString TheStringipSTextBlock = *ipSTextBlock->GetText().ToString();
					FString TheString = *IPEditableText->GetText().ToString();
					FString leftString;
					FString rightString;
					bool is = TheString.Split(":", &leftString, &rightString);

					if (TheStringipSTextBlock == TEXT("Context"))
					{


						//useUDP1.InitSocket();
						
						UE_LOG(LogTemp, Display, TEXT("OnClick: %s"), *TheString);
						UE_LOG(LogTemp, Display, TEXT("OnClick: %s"), *leftString);
						UE_LOG(LogTemp, Display, TEXT("OnClick: %s"), *rightString);
						ipSTextBlock->SetText(FText::FromString(TEXT("Disconnect")));
						MySocketObject = NewObject<USocketObject>();
						MySocketObject->Create(leftString, false, FCString::Atoi(*rightString));

					}
					if (TheStringipSTextBlock == TEXT("Disconnect"))
					{


						//useUDP1.StopSocket();
						MySocketObject->Close();
						ipSTextBlock->SetText(FText::FromString(TEXT("Context")));


					}
					return FReply::Handled();
				}))


			[
				SAssignNew(ipSTextBlock, STextBlock)
				.Text(FText::FromString(TEXT("Context")))




			]
		]
		]

	+ SGridPanel::Slot(1, 1).HAlign(HAlign_Fill).VAlign(VAlign_Center)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().FillWidth(1).VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateLambda([this]()
				{
					/*TArray<uint8> sendArray;
					FString ipFString = "192.168.0.158";
					sendArray.Init(5, 2);*/
					/*	useUDP1.SendUdpData(sendArray, ipFString, 8800);*/
					FString msgend = "0t";
					FString msg = *msgEditableTextBox->GetText().ToString()+ msgend;
					MySocketObject->SendData(msg);

					return FReply::Handled();
				}))
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("Ready")))

			]
		
		]
	+ SHorizontalBox::Slot().FillWidth(1).VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateLambda([this]()
				{
					/*TArray<uint8> sendArray;
					FString ipFString = "192.168.0.158";
					sendArray.Init(5, 2);*/
					/*	useUDP1.SendUdpData(sendArray, ipFString, 8800);*/
					FString msgend = "1t";
					FString msg = *msgEditableTextBox->GetText().ToString() + msgend;
					MySocketObject->SendData(msg);

					return FReply::Handled();
				}))
			
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("Start")))

			]
		]
		]
	+ SGridPanel::Slot(1, 2).HAlign(HAlign_Center).VAlign(VAlign_Center)
		[
			SAssignNew(msgEditableTextBox,SEditableTextBox)
			.Text(FText::FromString(TEXT("P1C1")))
		]
	+ SGridPanel::Slot(1, 3).HAlign(HAlign_Center).VAlign(VAlign_Center)
		[


				
			SNew(STextBlock)

		
		]
		]
	);
}
TSharedRef<SMyWidget> SMyWidget::New()
{
	return MakeShareable(new SMyWidget());
}