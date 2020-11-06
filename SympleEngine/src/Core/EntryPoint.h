#pragma once

#ifdef SY_PLATFORM_WINDOWS
extern Symple::Application* Symple::CreateApplication();

int main(int argc, char** argv)
{
	auto application = Symple::CreateApplication();
	application->Start();
	delete application;
}
#endif