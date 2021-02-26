#pragma once

#include "Symple/Engine/Core/Base.h"

int main(int argc, char *argv[]);

namespace Symple::Engine
{
    class SY_ENGINE_API Application
    {
    private:
        static Application *s_Instance;

        friend int ::main(int argc, char *argv[]);
    protected:
        virtual void Start() = 0;
    public:
    };

    Application *StartApplication();
}