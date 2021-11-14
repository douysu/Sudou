#pragma once
#include <iostream>
#ifdef SUDOU_PLATFORM_WINDOWS

extern Sudou::Application* Sudou::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Hello~" << std::endl;
	auto app = Sudou::CreateApplication();
	app->Run();
	delete app;
}

#endif // SUDOU_PLATFORM_WINDOWS