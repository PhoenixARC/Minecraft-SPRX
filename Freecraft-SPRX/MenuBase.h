#pragma once
#include "Freecraft.h"
extern int redColor[4];
extern int whiteColor[4];

enum eMenus {
	MainMenu,
	HostMiscMods,
	HostDamageMods,
	HostMovementMods,
	HostTNTMods,
	EntityMods,
	AllPlayerMods,
	WeatherMods,
	NonHostMovementMods,
	NonHostMiscMods,
	VisualMods
};

struct Menu {
	int CurrentMenu;
	int CurrentOpt;
	int MaxOption;
	void AddTitle(const wchar_t * title);
	void AddOption(const wchar_t * opt, void(*function)());
	template<typename arg_t>
	void AddOption(const wchar_t * opt, void(*function)(arg_t arg), arg_t arg);
};

struct Vars {

};

struct Self {
	Menu menu;
	Vars vars;
	bool isMenuOpen;
};

void RenderMenu();

extern Self self;
