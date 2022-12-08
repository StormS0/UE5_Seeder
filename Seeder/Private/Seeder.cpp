// Copyright Seeder, Inc. All Rights Reserved.

#include "Seeder.h"
#include "SeederStyle.h"
#include "SeederCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "SMyWidget.h"
static const FName SeederTabName("Seeder");

#define LOCTEXT_NAMESPACE "FSeederModule"

void FSeederModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FSeederStyle::Initialize();
	FSeederStyle::ReloadTextures();

	FSeederCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FSeederCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FSeederModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FSeederModule::RegisterMenus));
	
	/*FGlobalTabmanager::Get()->RegisterNomadTabSpawner(SeederTabName, FOnSpawnTab::CreateRaw(this, &FSeederModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FSeederTabTitle", "Seeder"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);*/
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(SeederTabName,
		FOnSpawnTab::CreateLambda([](const FSpawnTabArgs& SpawnTabArgs) {
			return SNew(SDockTab)
				.TabRole(ETabRole::NomadTab)
				[
					// Put your tab content here!
					SNew(SMyWidget)
				];
			}))
		.SetDisplayName(LOCTEXT("SMyWidgetTitle", "Seeder"))
				.SetMenuType(ETabSpawnerMenuType::Hidden);

}

void FSeederModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FSeederStyle::Shutdown();

	FSeederCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(SeederTabName);
}

TSharedRef<SDockTab> FSeederModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FSeederModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("Seeder.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FSeederModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(SeederTabName);
}

void FSeederModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FSeederCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FSeederCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSeederModule, Seeder)