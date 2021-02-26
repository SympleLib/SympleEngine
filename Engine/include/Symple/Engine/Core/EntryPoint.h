#pragma once

#include "Symple/Engine/Core/Base.h"
#include "Symple/Engine/Core/Application.h"

Symple::Engine::Application *Symple::Engine::StartApplication();

int main(int argc, char* argv[])
{
    auto *app = Symple::Engine::StartApplication();
    app->Start();
    delete app;
}