#pragma once
#include "Freecraft.h"

struct font_t;

template<typename R, typename... Arguments> inline R Call(long long function, Arguments... args);

int wcslen(const wchar_t * wchar);

font_t MakeString(const wchar_t * str);

void drawShadowText(uint32_t font, uint32_t r4, uint32_t x, uint32_t y, uint32_t color, uint32_t r8, uint32_t r9);
int textWidth(uint32_t font, uint32_t r4);

void UI_DrawText(const wchar_t * text, float x, float y, int * color);
void UI_DrawRightText(const wchar_t * text, float x, float y, int * color);
