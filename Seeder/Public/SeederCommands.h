// Copyright Seeder, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "SeederStyle.h"

class FSeederCommands : public TCommands<FSeederCommands>
{
public:

	FSeederCommands()
		: TCommands<FSeederCommands>(TEXT("Seeder"), NSLOCTEXT("Contexts", "Seeder", "Seeder Plugin"), NAME_None, FSeederStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};