#include <cstdlib>

extern __declspec(dllimport) void Test();

int main()
{
    Test();
    std::system("pause");
}