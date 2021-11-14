#pragma once
#include <iostream>

extern Sudou::Application* Sudou::CreateApplication();

int main(int argc, char** argv)
{
	std::cout << "Hello~" << std::endl;
	auto app = Sudou::CreateApplication();
	app->Run();
	delete app;
}