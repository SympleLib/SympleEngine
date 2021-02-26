#include <cstdio>

#include <Symple/Engine/SympleEngine.h>

class SandboxApp: public Symple::Engine::Application
{
private:
protected:
    virtual void Start() override
    { std::puts("Sandbox Application started!"); }
public:
};

Symple::Engine::Application *Symple::Engine::StartApplication()
{ return new SandboxApp; }