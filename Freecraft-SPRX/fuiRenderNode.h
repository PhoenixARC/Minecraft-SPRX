// This was an attempt to rewrite the FUI Rendering system, abandoned and depreciated until further notice
#pragma once
class fuiRenderNode
{
public:
	fuiRenderNode(void);
	~fuiRenderNode(void);
	void asEditText(void);
	void asTimeline(void);
	void clearScrollRectViewport(void);
	void disableCtor(void);
	void findNode(char const *);
};

