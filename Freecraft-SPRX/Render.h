
unsigned int
	R_top_Corner,
	R_Side,
	L_top_Corner,
	L_Side,
	R_bttm_Corner,
	L_bttm_Corner,
	Top_side,
	Bttm_side,
	center
	;

extern "C" int _sys_printf(const char* fmt, ...);
#define sysprintf _sys_printf

void DrawTile(int x, int y, unsigned int Tile)
{
	sysprintf("\nDRAWTILE");
}

void CreateMenu(int x, int y, int width, int height)
{
	DrawTile(x,y,R_top_Corner);
	DrawTile(x,y + (height * 8),L_top_Corner);
	DrawTile(x + (width * 8),y,R_bttm_Corner);
	DrawTile(x + (width * 8),y + (height * 8),L_bttm_Corner);
}
