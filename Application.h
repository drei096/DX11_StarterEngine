#pragma once
#include "Window.h"
#include "EngineTimer.h"

class Application
{
public:
	Application();
	//app loop
	int Execute();

private:
	void Update();

private:
	Window wnd;
	EngineTimer Timer;
};

