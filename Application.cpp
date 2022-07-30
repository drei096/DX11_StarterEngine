#include "Application.h"

Application::Application() : wnd(1024,768, L"Starter Game Engine")
{

}

int Application::Execute()
{
	while (true)
	{
		// process all messages pending, but to not block for new messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		Update();
	}
}

void Application::Update()
{
	//get delta time
	//const float t = Timer.Peek();

	// ********* TESTER CODE FOR GRAPX *************

	//bg behavior
	const float c = sin(Timer.Peek()) / 2.0f + 0.5f;
	//clear buffer
	wnd.GetGrapx().ClearBuffer(c, c, 1.0f);

	//draw here
	wnd.GetGrapx().DrawTestTriangle();

	//end frame
	wnd.GetGrapx().EndFrame();
	// ************* END OF TESTER CODE *************
}



