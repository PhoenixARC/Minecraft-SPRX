#pragma once
#include "Freecraft.h"
extern int redColor[4];
extern int whiteColor[4];
extern int greenColor[4];

enum eMenus {
	MainMenu,
	HostMiscMods,
	HostMiscMods1
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

