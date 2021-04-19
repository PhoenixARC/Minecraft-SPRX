
#include <sys/timer.h>
#include "MenuBase.h"

int redColor[4] = { 255, 0, 0, 255 };
int whiteColor[4] = { 255, 255, 255, 255 };
int greenColor[4] = { 255, 0, 128, 255 };


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
	UI_DrawText(opt, 65, 30 + (10 * MaxOption), (MaxOption == CurrentOpt) ? greenColor : whiteColor);
	MaxOption += 1;
}

template<typename arg_t>
void Menu::AddOption(const wchar_t * opt, void(*function)(arg_t arg), arg_t arg) {
	UI_DrawText(opt, 65, 30 + (10 * MaxOption), (MaxOption == CurrentOpt) ? greenColor : whiteColor);
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
			self.menu.AddTitle(L"MainMenu");
			self.menu.AddOption(L"SubMenu1", func);
			self.menu.AddOption(L"SubMenu2", func);
			self.menu.AddOption(L"SubMenu3", func);
		} break;
		case HostMiscMods: {
			self.menu.MaxOption = 0;
			self.menu.AddTitle(L"SubMenu1");
			self.menu.AddOption(L"Option1", func);
			self.menu.AddOption(L"Option2", func);
			self.menu.AddOption(L"Option3", func);
			self.menu.AddOption(L"Next Page >>", func);
		} break;
			case HostMiscMods1: {
			self.menu.MaxOption = 0;
			self.menu.AddTitle(L"SubMenu1-page1");
			self.menu.AddOption(L"Option4", func);
			self.menu.AddOption(L"Option5", func);
			self.menu.AddOption(L"Option6", func);
		} break;


		}
	}
	else
	{
		if(isMCButtonPressed(R1) && isMCButtonPressed(L1))
			self.isMenuOpen = true;
	}

}


Self self;

