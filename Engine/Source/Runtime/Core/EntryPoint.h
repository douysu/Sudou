#pragma once
#include "Runtime/stdafx.h"
#include "Log.h"

extern Sudou::Application* Sudou::CreateApplication();

int main(int argc, char** argv)
{
	Sudou::Log::Init();
	SD_CORE_WARN("Initialized Log");

	int a = 5;
	SD_INFO("Hello~ Var = {0}", a);

	auto app = Sudou::CreateApplication();
	app->Run();
	delete app;
}