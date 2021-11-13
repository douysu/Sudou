#pragma once

#ifdef SUDOU_PLATFORM_WINDOWS

extern Sudou::Application* Sudou::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Sudou::CreateApplication();
	app->Run();
	delete app;
}

#endif // SUDOU_PLATFORM_WINDOWS