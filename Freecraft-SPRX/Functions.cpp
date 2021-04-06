#include "Freecraft.h"




template<typename R, typename... Arguments> inline R Call(long long function, Arguments... args) {
	int toc_t[2] = { function, TOC };
	R(*temp)(Arguments...) = (R(*)(Arguments...))&toc_t;
	return temp(args...);
}

int wcslen(const wchar_t * wchar) {
	return Call<int>(0x00CB32D8, wchar);
}

font_t MakeString(const wchar_t * str) {
	__builtin_return_address;
	font_t font;
	font.text = str;
	font.dataType = 7;
	font.wcstrlen = wcslen(str);
	font.wcstrlen1 = wcslen(str) + 3;
	font.unknown1 = 1.0625f;
	font.unknown1 = 1.0f;
	font.unknown1 = 1.0078125f;
	return font;
}

void drawShadowText(uint32_t font, uint32_t r4, uint32_t x, uint32_t y, uint32_t color, uint32_t r8, uint32_t r9) {
	Call<void>(0x00A7E2E8, font, r4, x, y, color, r8, r9);
}
int textWidth(uint32_t font, uint32_t r4) {
	return Call<int>(0x00A7DB38, font, r4);
}

void UI_DrawText(const wchar_t * text, float x, float y, int * color) {
	drawShadowText(mc->theMinecraft->fontRenderer, (uint32_t)&MakeString(text), x, y, Color_s(color[3], color[0], color[1], color[2]), 0, 1);
}

void UI_DrawRightText(const wchar_t * text, float x, float y, int * color) {
	int width = textWidth(mc->theMinecraft->fontRenderer, (uint32_t)&MakeString(text));
	drawShadowText(mc->theMinecraft->fontRenderer, (uint32_t)&MakeString(text), x - width, y, Color_s(color[3], color[0], color[1], color[2]), 0, 1);
}

// Host Menu Functions

