
#include <sys/timer.h>
#include "MenuBase.h"

int redColor[4] = { 255, 0, 0, 255 };
int whiteColor[4] = { 255, 255, 255, 255 };


void sleep(usecond_t time) {
	sys_timer_usleep(time * 1000);
}

void RenderMainMenu()
{
	self.menu.CurrentMenu = MainMenu;
}

void RenderHostMenu()
{
	self.menu.CurrentMenu = HostMiscMods;
}



void Menu::AddTitle(const wchar_t * title) {
	UI_DrawText(title, 63, 15, whiteColor);
}


void Menu::AddOption(const wchar_t * opt, void(*function)()) {
	UI_DrawText(opt, 65, 30 + (10 * MaxOption), (MaxOption == CurrentOpt) ? redColor : whiteColor);
	MaxOption += 1;
}

template<typename arg_t>
void Menu::AddOption(const wchar_t * opt, void(*function)(arg_t arg), arg_t arg) {
	UI_DrawText(opt, 65, 30 + (10 * MaxOption), (MaxOption == CurrentOpt) ? redColor : whiteColor);
	MaxOption += 1;
}
void func() 
{
	switch(self.menu.CurrentMenu)
	{
	case(MainMenu):
		switch(self.menu.CurrentOpt)
		{
		case(0):
			RenderHostMenu();
			self.menu.MaxOption = 0;
			self.menu.CurrentOpt = 0;
			break;
		case(1):
			break;
		case(2):
			break;
		case(3):
			break;
		case(4):
			break;
		case(5):
			break;
		case(6):
			break;
		case(7):
			break;
		case(8):
			break;
		case(9):
			break;
		}
		break;
	case(HostMiscMods):
		switch(self.menu.CurrentOpt)
		{
		case(0):
			break;
		case(1):
			break;
		case(2):
			break;
		case(3):
			break;
		case(4):
			break;
		case(5):
			break;
		case(6):
			break;
		case(7):
			break;
		case(8):
			break;
		case(9):
			break;
		case(10):
			break;
		case(11):
			break;
		case(12):
			break;
		case(13):
			break;
		case(14):
			break;
		case(15):
			break;
		case(16):
			break;
		case(17):
			self.menu.CurrentMenu = HostMiscMods1;
			self.menu.MaxOption = 0;
			self.menu.CurrentOpt = 0;
			break;
		}
		break;
	}
}

#include "PS3Pad.h"




void RenderMenu() {
	if(self.isMenuOpen){
	
				if (isMCButtonPressed(UP))
				{
					self.menu.CurrentOpt = self.menu.CurrentOpt - 1;
					sleep(50);
				}

				if (isMCButtonPressed(DOWN))
				{
					self.menu.CurrentOpt = self.menu.CurrentOpt + 1;
					sleep(50);
				}

				if(self.menu.CurrentOpt > self.menu.MaxOption)
				{
					self.menu.CurrentOpt = 0;
				}

				if(self.menu.CurrentOpt < 0)
				{
					self.menu.CurrentOpt = self.menu.MaxOption;
				}
				
				if (isMCButtonPressed(X))
				{
					self.menu.CurrentOpt = 0;
					func();
					printf("Press 'X'");
					sleep(50);
				}

				if (isMCButtonPressed(O))
				{
					self.menu.CurrentOpt = 0;
					RenderMainMenu();
					printf("Press 'O'");
					sleep(50);
				}
				
				if(isMCButtonPressed(O) && self.menu.CurrentMenu == MainMenu)
					self.isMenuOpen = false;

	self.menu.MaxOption = 0;
	switch (self.menu.CurrentMenu) {

		case MainMenu: {
			self.menu.MaxOption = 0;
			self.menu.AddTitle(L"Freecraft SPRX");
			self.menu.AddOption(L"Host Misc Mods", func);
			self.menu.AddOption(L"Host Damage Mods", func);
			self.menu.AddOption(L"Host Movement Mods", func);
			self.menu.AddOption(L"Host TNT Mods", func);
			self.menu.AddOption(L"Entity Mods", func);
			self.menu.AddOption(L"All Player Mods", func);
			self.menu.AddOption(L"Weather Mods", func);
			self.menu.AddOption(L"Non-Host Movement Mods", func);
			self.menu.AddOption(L"Non-Host Misc Mods", func);
			self.menu.AddOption(L"Visual Mods", func);
		} break;
		case HostMiscMods: {
			self.menu.MaxOption = 0;
			self.menu.AddTitle(L"Title {GAME_STATE}");
			self.menu.AddOption(L"Remove XP", func);
			self.menu.AddOption(L"Max XP", func);
			self.menu.AddOption(L"Gun Items", func);
			self.menu.AddOption(L"Auto Save", func);
			self.menu.AddOption(L"Reverse Knockback", func);
			self.menu.AddOption(L"Anti Knockback", func);
			self.menu.AddOption(L"Knockback", func);
			self.menu.AddOption(L"Infinite Breath", func);
			self.menu.AddOption(L"Spectral Arrows", func);
			self.menu.AddOption(L"Entity Godmode", func);
			self.menu.AddOption(L"Bypass Stack Limit", func);
			self.menu.AddOption(L"Remove Hit Delay", func);
			self.menu.AddOption(L"Stop Gravity", func);
			self.menu.AddOption(L"Remove Water", func);
			self.menu.AddOption(L"Burn In Water", func);
			self.menu.AddOption(L"Lobby Message", func);
			self.menu.AddOption(L"Infinite Place", func);
			self.menu.AddOption(L"Next Page >>", func);
		} break;
			case HostMiscMods1: {
			self.menu.MaxOption = 0;
			self.menu.AddTitle(L"Title {GAME_STATE}");
			self.menu.AddOption(L"No Grab", func);
			self.menu.AddOption(L"No Fall", func);
			self.menu.AddOption(L"No Grab 2", func);
			self.menu.AddOption(L"Max Pickup", func);
			self.menu.AddOption(L"Unlimited Arrows", func);
			self.menu.AddOption(L"Potion Fly Arrows", func);
			self.menu.AddOption(L"Remove Arrows", func);
			self.menu.AddOption(L"Block Arrows", func);
			self.menu.AddOption(L"Change Arrow Direction", func);
			self.menu.AddOption(L"Stop Bow", func);
			self.menu.AddOption(L"Fast Bow", func);
			self.menu.AddOption(L"Lock Gamemode", func);
		} break;

		case HostDamageMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		case HostMovementMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		case HostTNTMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		case EntityMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		case AllPlayerMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		case WeatherMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		case NonHostMovementMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		case NonHostMiscMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		case VisualMods: {
			self.menu.AddTitle(L"Title");
			self.menu.AddOption(L"", func);
		} break;

		}
	}
	else
	{
		if(isMCButtonPressed(SQUARE) && isMCButtonPressed(L1))
			self.isMenuOpen = true;
	}

}


Self self;

