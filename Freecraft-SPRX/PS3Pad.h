
// This code was forked from https://github.com/MisakiDev/Minecraft-SPRX-Source-Code
// Let us thank Misaki for his contribution to the development of new Minecraft SPRXs

//For Buttons


	unsigned int buttonMonitoring = 0x3000CF79; //Button Monitoring for Minecraft 1.84

	unsigned int
		X = 0x100,
		O = 0x200,
		SQUARE = 0x400,
		TRIANGLE = 0x800,
		UP = 0x40000,
		DOWN = 0x80000,
		LEFT = 0x100000,
		RIGHT = 0x200000,
		R1 = 0x4000,
		R2 = 0x0, //No need
		R3 = 0x10000,
		L1 = 0x8000,
		L2 = 0x0, //No need
		L3 = 0x20000,
		START = 0x2000,
		SELECT = 0x1000
		;
	
	unsigned int getMCButtons()
	{
		return *(unsigned int*)(buttonMonitoring);
	}

	bool isMCButtonPressed(unsigned int Buttons)
	{
		return (getMCButtons() & Buttons) > 0;
	}