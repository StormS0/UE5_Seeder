// Copyright 2022 Seeder, Inc. All Rights Reserved.

#include "SeederCommands.h"

#define LOCTEXT_NAMESPACE "FSeederModule"

void FSeederCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "Seeder", "Bring up Seeder window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
