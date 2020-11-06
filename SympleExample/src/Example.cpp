#include <SympleEngine.h>

class Example : public Symple::Application
{
public:
	Example() {}

	~Example() {}
};

Symple::Application* Symple::CreateApplication()
{
	return new Example;
}