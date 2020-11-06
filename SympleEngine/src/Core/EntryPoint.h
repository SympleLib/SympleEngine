#pragma once

#ifdef SY_PLATFORM_WINDOWS
extern Symple::Application* Symple::CreateApplication();

int main(int argc, char** argv)
{
	Symple::Console::Initialize();
	SY_CORE_DEBUG("Initialized Core Log!");
	SY_DEBUG("Initialized Program Log!");

	auto application = Symple::CreateApplication();
	application->Start();
	delete application;
}
#endif